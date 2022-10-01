   
#include <bits/stdc++.h>
using namespace std;

#define ff                 first
#define ss                 second
#define ll                 long long int
#define ld                 long double
#define pb                 push_back
#define mp                 make_pair
#define pii                pair<ll, ll>
#define vi                 vector<ll>
#define vs                 vector<string>=
#define mii                map<ll, ll>
#define ump                unordered_map<ll, ll>
#define mid(l,r)           (l+(r-l)/2)
#define pq_max             priority_queue<ll>
#define pq_min             priority_queue<int, vi, greater<ll> >
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define mod                1000000007
#define inf                1e18
#define ps(x, y)           fixed<<setprecision(y)<<x
#define mk(arr,n,type)     type *arr = new type[n];
#define w(x)               int x; cin>>x; while(x--)
#define loop(i,a,b)     for(int i=(a);i<=(b);i++)

void file_i_o(){
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   #ifndef ONLINE_JUDGE
       freopen("C:/Users/arnav/Desktop/InputOutput/input.txt", "r", stdin);
        freopen("C:/Users/arnav/Desktop/InputOutput/output.txt", "w", stdout);
    #endif 
}     

vector<pair<int, int>> resolve(string s) {

vector<pair<int, int>> v;

for (int i=0;i<s.size();i++) {

string num = "";

if(s[i]=='+' || s[i] == '-'){ 
num += s[i];
i++;

} 
while(i<s.size() && (s[i]>='0' && s[i]<='9')){ 
 num += s[i];
i++;
}

string exp = ""; 
if(i>= s.size()){

exp = "0";

} 
i++; // char 
i++; // ^

if(i<s.size() && s[i]=='+' || s[i] == '-') {
exp += s[i]; 
i++;
} 
while(i<s.size() && (s[i]>='0' && s[i]<='9')){ 
    exp += s[i];
    i++;

} 
if(exp == ""){

exp = "1";

}
 v.push_back({stoi (num), stoi (exp)});
i--;
}



return v;

}

string MathChallenge (string str){ 
vector<pair<int, int>> a, b, mul;

char c;

if(1){

int id = 1;

string temp1 = "";

for(;;id++){

if(str[id]>='a' && str[id]<='z'){

c = str[id];

} 
if(str[id] == ')') break; 
temp1 += str[id];

}
 id += 2;

string temp2 = "";

for(;;id++){

if(str[id] == ')') break; 
temp2 += str[id];

}

a = resolve(temp1);

b = resolve(temp2);

} 
for (int i=0;i<a.size();i++) { 
    for (int j=0;j<b.size();j++){

mul.push_back({ a[i].first * b[j].first, a[i].second + b[j].second });

}

} 
if(1){

map<int, int> m; 
for (auto &[x,y]: mul){

m[y] += x;

} 
mul.clear();

for (auto &[x,y]: m){ 
    mul.push_back({y, x});

}

}
sort (mul.begin(), mul.end(), [&](pair<int,int> a,pair<int, int> b){ return a.second > b.second;});

string ans = "";

for (auto &[x,y]: mul){ 
    if(x > 0 && ans.size() > 0){ 
        ans += "+";
}

if(x != 1) ans += to_string(x);

if(y != 0){

ans += c; 
if(y != 1) { 
    ans += '^';

ans += to_string(y);

}

}

}

return ans;

}



int main(int argc, char const *argv[])
 {
 
     file_i_o();
     cout << MathChallenge (" (1x) (2x^-2+1)"); return 0;
     return 0;

 }