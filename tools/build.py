import os
import shutil

path_root = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
path_dist = os.path.join(path_root, 'dist')
path_dist_python = os.path.join(path_dist, 'python')
path_dist_javascript = os.path.join(path_dist, 'javascript')
path_dist_lua = os.path.join(path_dist, 'lua')


def ensure_dir(folder):
    if isinstance(folder, str):
        if not os.path.exists(folder):
            os.makedirs(folder)
        return

    if isinstance(folder, list):
        for _folder in folder:
            ensure_dir(_folder)
        return

    raise Exception()


def remove_dir(folder):
    if isinstance(folder, str):
        shutil.rmtree(folder, ignore_errors=True)
        return

    if isinstance(folder, list):
        for _folder in folder:
            remove_dir(_folder)
        return

    raise Exception()


def copy_dir(dir_src, dir_dst):
    for filename in os.listdir(dir_src):
        shutil.copy(os.path.join(dir_src, filename), dir_dst)


if __name__ == '__main__':
    remove_dir(path_dist)
    ensure_dir([path_dist, path_dist_python, path_dist_javascript, path_dist_lua])

    copy_dir(os.path.join(path_root, 'src', 'python'), path_dist_python)
    copy_dir(os.path.join(path_root, 'src', 'core'), path_dist_python)
    copy_dir(os.path.join(path_root, 'src', 'javascript'), path_dist_javascript)
    copy_dir(os.path.join(path_root, 'src', 'core'), path_dist_javascript)
    copy_dir(os.path.join(path_root, 'src', 'lua'), path_dist_lua)
    copy_dir(os.path.join(path_root, 'src', 'core'), path_dist_lua)

