//https://www.codingame.com/ide/puzzle/1d-spreadsheet
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
map<ll,ll>mp;
vector< vector<string> > v1;

ll solve(vector<string>&v2, ll order);

ll getline(string str)
{
    ll res;
    string sub = str.substr(1,str.size());
    //cout<<"this is sub->"<<sub<<"\n";
    istringstream(sub) >> res;
    if(mp.find(res) != mp.end())
    {
        return mp[res];
    }
    return solve(v1[res],res);
}

ll solve(vector<string>&v2, ll order)///   ADD $1 20
{

    string operation = v2[0];
    string arg_1 = v2[1];
    string arg_2 = v2[2];
     //cout<<order<<"----this->"<<arg_1<<" - "<<arg_2<<"\n";
    ll num1 , num2;
    if(arg_1[0] == '$')
    {
        string sub = arg_1.substr(1,arg_1.size());
        istringstream(sub) >> num1;
        //cout<<"this->"<<num1<<"\n";
        if(mp.find(num1) != mp.end()) num1 = mp[num1];
        else num1 = mp[order] = solve(v1[num1],num1);
    }
    else istringstream(arg_1) >> num1;

    if(arg_2[0] == '$')
    {
        string sub = arg_2.substr(1,arg_2.size());
        istringstream(sub) >> num2;
        if(mp.find(num2) != mp.end()) num2 = mp[num2];
        else num2 = mp[order] = solve(v1[num2],num2);
    }
    else istringstream(arg_2) >> num2;

    if(operation == "VALUE") return mp[order] = num1;

     if (operation == "ADD")
    {
        ll sum = num1+num2;
        return mp[order] = sum;
    }
     if(operation == "SUB")
    {
        ll sub = num1 - num2;
        return mp[order] = sub;
    }
     if(operation == "MULT")
    {
        ll multi = num1*num2;
        return  mp[order] = multi;
    }

}
int main()
{

    /*
    2
    ADD $1 20
    VALUE 32 _
    */
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        vector<string> temp;
        string operation;
        string arg_1;
        string arg_2;
        cin >> operation >> arg_1 >> arg_2;
        //cout << operation <<" "<< arg_1 <<" "<< arg_2<<"\n";
        cin.ignore();
        temp.push_back(operation);
        temp.push_back(arg_1);
        temp.push_back(arg_2);

        v1.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
      ll x = solve(v1[i],i);
      //  cout<<"here"<<x<<"\n";
        //cout << "1" << endl;
    }
    for(auto &it:mp)
    {
        //cout<<it.first<<"->"<<it.second<<"\n";
         cout<<it.second<<"\n";
    }
}

/*
92
SUB $33 $64
ADD $60 $60
ADD $61 $61
SUB $76 $80
SUB $25 $59
ADD $58 $28
ADD $88 $59
ADD $32 $32
ADD $83 $21
ADD $69 $39
ADD $57 $64
ADD $26 $26
ADD $1 $1
SUB $62 $68
ADD $73 $1
ADD $50 $27
SUB $24 $2
ADD $14 $12
ADD $10 $89
SUB $67 $35
ADD $58 $58
ADD $7 $7
SUB $0 $89
ADD $20 $20
SUB $43 $61
SUB $53 $11
ADD $37 $37
ADD $82 $47
ADD $90 $2
ADD $89 $89
ADD $85 $85
SUB $91 $47
ADD $69 $69
SUB $46 $86
SUB $42 $20
ADD $12 $12
ADD $56 $8
ADD $72 $72
ADD $9 $32
ADD $30 $77
ADD $80 $48
ADD $79 $81
SUB $16 $58
SUB $44 $56
SUB $63 $21
ADD $20 $5
SUB $49 $81
ADD $54 $54
ADD $29 $18
SUB $34 $23
ADD $47 $47
SUB $74 $32
SUB $17 $72
SUB $71 $26
ADD $59 $59
ADD $15 $68
ADD $21 $21
ADD $86 $41
ADD $2 $2
ADD $11 $11
ADD $80 $80
ADD $56 $56
SUB $31 $50
SUB $51 $7
ADD $86 $86
ADD $72 $35
SUB $75 $30
SUB $70 $12
ADD $50 $50
ADD $30 $30
SUB $84 $1
SUB $52 $37
VALUE 1 _
ADD $40 $60
SUB $66 $69
SUB $13 $85
SUB $22 $29
ADD $55 $85
ADD $37 $65
ADD $23 $45
ADD $29 $29
ADD $23 $23
ADD $54 $6
ADD $38 $7
SUB $3 $60
ADD $68 $68
ADD $81 $81
ADD $78 $26
ADD $87 $11
ADD $64 $64
ADD $61 $36
SUB $4 $54

*/
