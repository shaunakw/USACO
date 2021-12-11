import os, sys
from datetime import date

loc = sys.argv[1]
name = sys.argv[2]
vars = sys.argv[3:]

def join_vars(begin='', join='', end=''):
    return f'{begin}{join.join(vars)}{end}' if len(sys.argv) > 3 else ''

vars_cpp_init = join_vars(begin='int ', join=', ', end=';')
vars_cpp_read = join_vars(begin='cin >> ', join=' >> ', end=';')
vars_java = join_vars(begin='int ', join=f' = in.nextInt();\n\t\tint ', end=' = in.nextInt();')

config = { # [path, template, input_type]
    'sl': ['starleague/gold', 'cpp_old', 'inout'],
    'comp': [f'comp/{date.today().strftime("%b%y")}', 'cpp', 'none'],
    'prac': ['practice', 'cpp_old', 'inout'],
    'club': ['programmingclub', 'java_old', 'inout'],
}

if loc not in config:
    print(f'Sorry, \'{loc}\' isn\'t a valid location. Valid locations are: {list(config.keys())}.')
else:
    path = f'{config[loc][0]}/{name}'
    template = config[loc][1]
    input_type = config[loc][2]
    ext = template.split('_')[0]

    code = open(f'templates/{template}.txt').read() \
        .replace('%name%', name) \
        .replace('%vars_cpp_init%', vars_cpp_init) \
        .replace('%vars_cpp_read%', vars_cpp_read) \
        .replace('%vars_java%', vars_java)

    try:
        os.makedirs(path)
        os.chdir(path)

        file = open(f'{name}.{ext}', 'w')
        file.write(code)
        file.close()

        if input_type == 'inout':
            open(f'{name}.out', 'x')
            open(f'{name}.in', 'x')

        print('Files successfully created.')
    except OSError:
        print(f'Sorry, \'{name}\' already exists in that location.')
