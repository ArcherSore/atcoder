#include <iostream>
using namespace std;

int main(void) {
    string s, ans;
    cin >> s;
    
    for(auto c : s){
        ans += c;
        if (ans.size() >= 3 && ans.substr(ans.size() - 3) == "ABC") 
            ans.erase(ans.end() - 3, ans.end());
    }
    cout << ans << endl;
    
    return 0;
}