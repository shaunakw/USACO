import os
import sys
from datetime import date

loc = sys.argv[1]
name = sys.argv[2]
ext = 'java' if loc == 'club' else 'cpp'

vars_list = [i.upper() for i in sys.argv[3:]]
nl = '\n'
tab = '\t'

def join_vars(begin='', join='', end=''):
    return f'{begin}{join.join(vars_list)}{end}' if len(sys.argv) > 3 else ''

code = {
    'java': \
f'''import java.io.*;
import java.util.*;

public class {name} {{
    public static void main(String[] args) throws IOException {{
        Scanner in = new Scanner(new File("{name}.in"));
        PrintWriter out = new PrintWriter("{name}.out");

        {join_vars(begin='int ', join=f' = in.nextInt();{nl}{tab}{tab}int ', end=' = in.nextInt();')}

        out.close();
    }}
}}
''',

    'cpp': \
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
{join_vars(begin=f'{nl}int ', join=', ', end=f';{nl}')}
int main() {{
    setIO();
    {join_vars(begin='cin >> ', join=' >> ', end=f';{nl}{tab}')}
    
    
    return 0;
}}
'''
}

paths = {
    'sl': 'starleague/gold',
    'comp': f'comp/{date.today().strftime("%b%y")}',
    'prac': 'practice',
    'club': 'programmingclub'
}

if loc not in paths:
    print(f'Sorry, \'{loc}\' isn\'t a valid location. Valid locations are: {list(paths.keys())}.')
else:
    path = f'{paths[loc]}/{name}'
    try:
        os.makedirs(path)
        os.chdir(path)

        open(f'{name}.out', 'x')
        open(f'{name}.in', 'x')
        file = open(f'{name}.{ext}', 'w')
        file.write(code[ext])
        file.close()

        print('Files successfully created')
    except OSError:
        print(f'Sorry, \'{name}\' already exists in that location.')
