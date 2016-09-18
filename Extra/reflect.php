<?php
define('TAB', '    ');
define('MODULE', 'rabbit');

$incs = array (
	'common.h',
	'rabbit.h',
	'rabbit_core.h',
);

$funcs = array (
	array ('sleep', '', 'I'),
	array ('keypress', '', 's'),
	array ('moveto', '', 'II'),
	array ('click', '', ''),
	array ('doubleclick', '', ''),
	array ('rightclick', '', ''),
	array ('findcolor', 'ii', 'IIIIId'),
	array ('mouse_fetch_cursor', 'I', ''),
	array ('findwindow', 'K', 's'),
	array ('get_window_rect', 'iiii', 'K'),
);

function fetch_type_c($type) {
	switch ($type) {
		default:
			return 'const void *';
			break;
		case 's':
			return 'const char *';
			break;
		case 'i':
			return 'int';
			break;
		case 'I':
			return 'unsigned int';
			break;
		case 'L':
			return 'long long';
			break;
		case 'K':
			return 'unsigned long long';
			break;
		case 'd':
			return 'double';
			break;
	}
}

function fetch_type_lua($type) {
	switch ($type) {
		default:
			return 'userdata';
			break;
		case 's':
			return 'string';
			break;
		case 'i':
		case 'L':
			return 'integer';
			break;
		case 'I':
		case 'K':
			return 'unsigned';
			break;
		case 'd':
			return 'number';
			break;
	}
}

function implode_args_suffix($args) {
	if (count($args) > 0) {
		return ', '.implode(', ', $args);
	} else {
		return '';
	}
}

function echo_func_python ($name, $rets, $args) {
	echo 'PyObject * _python_'.$name.'(PyObject * self, PyObject * args) {'."\r\n";
	$rets_c = array();
	$args_rc = array();
	$params = array();
	for($i=0; $i<count($rets); $i++) {
		echo TAB.fetch_type_c($rets[$i]).' ret_'.$i.";\r\n";
		array_push($rets_c, 'ret_'.$i);
		array_push($params, '&ret_'.$i);
	}
	for($i=0; $i<count($args); $i++) {
		echo TAB.fetch_type_c($args[$i]).' arg_'.$i.";\r\n";
		array_push($args_rc, '&arg_'.$i);
		array_push($params, 'arg_'.$i);
	}
	echo TAB.'int tupleret = PyArg_ParseTuple(args, "'.implode($args).'"'.implode_args_suffix($args_rc).');'."\r\n";
	echo TAB.$name.'('.implode(', ', $params).');'."\r\n";
	echo TAB.'return Py_BuildValue("'.implode($rets).'"'.implode_args_suffix($rets_c).');'."\r\n";
	echo '}'."\r\n";
}

function echo_func_lua ($name, $rets, $args) {
	echo 'int _lua_'.$name.'(lua_State * L) {'."\r\n";
	echo TAB.'int argc = lua_gettop(L);'."\r\n";
	$params = array();
	for($i=0; $i<count($rets); $i++) {
		echo TAB.fetch_type_c($rets[$i]).' ret_'.$i.";\r\n";
		array_push($params, '&ret_'.$i);
	}
	for($i=0; $i<count($args); $i++) {
		echo TAB.fetch_type_c($args[$i]).' arg_'.$i.' = lua_to'.fetch_type_lua($args[$i]).'(L, '.($i+1).');'."\r\n";
		array_push($params, 'arg_'.$i);
	}
	echo TAB.$name.'('.implode(', ', $params).');'."\r\n";
	for($i=0; $i<count($rets); $i++) {
		echo TAB.'lua_push'.fetch_type_lua($rets[$i]).'(L, ret_'.$i.");\r\n";
	}
	echo TAB.'return '.count($rets).";\r\n";
	echo '}'."\r\n";
}

// ----------------------------------------------------------------------------------------------------------------------------

foreach ($incs as $inc) {
	echo '#include "'.$inc.'"'."\r\n";
}
echo "\r\n";
foreach ($funcs as $func) {
	$rets = preg_split('//', $func[1], -1, PREG_SPLIT_NO_EMPTY);
	$args = preg_split('//', $func[2], -1, PREG_SPLIT_NO_EMPTY);
	echo_func_python(MODULE.'_'.$func[0], $rets, $args);
	echo "\r\n";
	echo_func_lua(MODULE.'_'.$func[0], $rets, $args);
	echo "\r\n";
}

echo 'luaL_Reg _'.MODULE.'_lib[] = {'."\r\n";
foreach ($funcs as $func) {
	echo TAB.'{ "'.$func[0].'", _lua_'.MODULE.'_'.$func[0].' },'."\r\n";
}
echo TAB.'{ NULL, NULL }'."\r\n".'};'."\r\n";
echo "\r\n";

echo 'PyMethodDef _'.MODULE.'_defs[] = {'."\r\n";
foreach ($funcs as $func) {
	echo TAB.'{ "'.$func[0].'", _python_'.MODULE.'_'.$func[0].', METH_VARARGS, NULL },'."\r\n";
}
echo TAB.'{ NULL, NULL, 0, NULL }'."\r\n".'};'."\r\n";
echo "\r\n";

echo 'void '.MODULE.'_init(RABBIT_MODE mode, void * instance) {'."\r\n";
echo TAB.'if (mode == RABBIT_MODE_LUA) {'."\r\n";
echo TAB.TAB.'lua_State * L = (lua_State *)instance;'."\r\n";
echo TAB.TAB.'luaL_newlib(L, _'.MODULE.'_lib);'."\r\n";
echo TAB.TAB.'lua_setglobal(L, "'.MODULE.'");'."\r\n";
echo TAB.'}'."\r\n";
echo TAB.'else {'."\r\n";
echo TAB.TAB.'Py_InitModule("'.MODULE.'", _'.MODULE.'_defs);'."\r\n";
echo TAB.TAB.'PyRun_SimpleString("import '.MODULE.'");'."\r\n";
echo TAB.'}'."\r\n";
echo '}'."\r\n";


