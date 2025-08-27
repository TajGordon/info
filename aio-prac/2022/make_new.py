import sys
import os

def main():
    if len(sys.argv) < 2:
        print("Usage: python make_new.py <name>")
        sys.exit(1)
    name = sys.argv[1]
    filename = f"{name}.cpp"
    if os.path.exists(filename):
        print(f"File '{filename}' already exists.")
        sys.exit(1)
    template = '''#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf LONG_LONG_MAX
#define pb push_back

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    return 0;
}
'''
    with open(filename, 'w') as f:
        f.write(template)
    print(f"Created {filename}")

if __name__ == "__main__":
    main()
