import os
import sys
from datetime import date

loc = sys.argv[1]
name = sys.argv[2]

paths = {
    'sl': 'starleague/gold',
    'comp': f'comp/{date.today().strftime("%b%y")}',
    'prac': 'practice',
}

vars_list = [i.upper() for i in sys.argv[3:]]
nl = '\n'
tab = '\t'


def if_vars(s):
    return s if len(sys.argv) > 3 else ''


code = \
f'''#include <bits/stdc++.h>

#define fori(i, a) for(int i = 0; i < a; ++i)
#define trav(i, a) for(auto& i : a)

using namespace std;

void setIO() {{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("{name}.in", "r", stdin);
    freopen("{name}.out", "w", stdout);
}}
{if_vars(f'{nl}int {", ".join(vars_list)};{nl}')}
int main() {{
    setIO();
    {if_vars(f'cin >> {" >> ".join(vars_list)};{nl}{tab}')}
    
    
    return 0;
}}
'''

if loc not in paths:
    print(f'Sorry, \'{loc}\' isn\'t a valid location. Valid locations are: {list(paths.keys())}.')
else:
    path = f'{paths[loc]}/{name}'
    try:
        os.makedirs(path)
        os.chdir(path)

        open(f'{name}.out', 'x')
        open(f'{name}.in', 'x')
        file = open(f'{name}.cpp', 'w')
        file.write(code)
        file.close()

        print('Files successfully created')
    except OSError:
        print(f'Sorry, \'{name}\' already exists in that location.')
