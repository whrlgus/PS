#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

class Node {
public:
    Node *prev, *next;
    int index;
};

void move(Node **head, int amount, bool toNext) {
    while(amount) {
        *head = toNext ? (*head)->next : (*head)->prev;
        --amount;
    }
}

string solution(int n, int k, vector<string> cmd) {
    Node *head = new Node();
    head->index = 0;
    Node *curr = head;
    f(i,1,n) {
        Node *next = new Node();
        next->index = i;
        next->prev = curr;
        curr->next = next;
        curr = next;
    }
    move(&head,k,true);
    
    string result = string(n, 'O');
    stack<Node*> s;
    
    for(auto str: cmd) {
        stringstream ss(str);
        string command;
        ss>>command;
        if(command=="U"||command=="D"){
            int amount;
            ss>>amount;
            move(&head, amount, command == "D");
        }else if(command=="C"){
            if(head->prev)head->prev->next=head->next;
            if(head->next)head->next->prev=head->prev;
            result[head->index]='X';
            s.push(head);
            if(head->next)head=head->next;
            else head=head->prev;
        }else {
            Node *curr=s.top();
            s.pop();
            if(curr->prev)curr->prev->next=curr;
            if(curr->next)curr->next->prev=curr;
            result[curr->index]='O';
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout<<solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"});
    return 0;
}


