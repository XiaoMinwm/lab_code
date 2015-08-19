#include <iostream>
using namespace std;
#include <stack>
#include <cstring>

class Exp {
    stack<char> ops;
    stack<double> ds;
    double v, lh ,rh;
    char op;

public:
    double calinput() {
        do {
            readdata();
            skipspace();
        } while(readop());

        calremain();
        return v;
    }

    void readdata() {
    while(!(cin >> v)) {
    cin.clear();
    cin >> op;
    if(op!='(') throw string("在该出现数值的地方遇到了")+op;
    ops.push(op);
    }

    ds.push(v);
    }

    void skipspace() {
        while(cin.peek()==' ' || cin.peek()=='\t') cin.ignore();
    }

    bool readop() {
        while((op=cin.get())==')') {
            while((ops.top()!='(')) {
            rh = ds.top();
            ds.pop();
            lh=ds.top();
            ds.pop();
            ds.push(cal(lh, ops.top(), rh));
            ops.pop();
        }
        ops.pop();
    }
    if(op=='\n') return false;
    if(strchr("+-*/", op)==NULL)
        throw string("无效的运算符")+op;
    while(!ops.empty()&&ops.top()!='('&&!prior(op, ops.top())) {
            rh = ds.top();
            ds.pop();
            lh=ds.top();
            ds.pop();
            ds.push(cal(lh, ops.top(), rh));
            ops.pop();
    }
    ops.push(op);
  }

    void calremain() {
        while(!ops.empty()) {
            rh = ds.top();
            ds.pop();
            lh=ds.top();
            ds.pop();
            ds.push(cal(lh, ops.top(), rh));
            ops.pop();
        }

        if(ds.size()!=1) throw string("无效的表达式");
            v = ds.top();
            ds.pop();
    }

    double cal(double lh, char op, double rh) {
        return op=='+' ? lh+rh:op=='-' ? lh-rh:op=='*' ? lh*rh:lh/rh;
    }

    bool prior(char o1, char o2) {
        return o1!='+' && o1!='-' && o2!='*' && o2!='/';
    }
};

int main() {
    Exp e;
    try{
      cout << e.calinput() << endl;
   } catch(const string& e) {
    cout << e << endl;
}
}
