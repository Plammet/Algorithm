#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int number;
    node* prev;
    node* next;
    node(int n, node* prev, node* next) : number(n), prev(prev), next(next){};
};

string solution(int n, int k, vector<string> cmd) {
    string answer = "O";
    
    node* prev = new node(0, NULL, NULL);
    node* newnode;
    node* now;
    vector<node*> delete_stack;
    
    if (k==0) now = prev;
    
    for (int i=1; i<n; i++){
        newnode = new node(i, prev, NULL);
        prev->next = newnode;
        prev = newnode;
        
        answer.push_back('O');
        if (i==k) now = newnode;
    }

    for (string c : cmd){
        if (c[0] == 'U'){
            
            string num(c.begin() + 2, c.end());
            
            for (int i=0; i<stoi(num); i++)
                now = now->prev;         
        }
        
        if (c[0] == 'D'){
            
            string num(c.begin() + 2, c.end());
            
            for (int i=0; i<stoi(num); i++)
                now = now->next;         
        }
        
        if (c[0] == 'C'){
            delete_stack.push_back(now);
            answer[now->number] = 'X';
            
            if(now->prev)
                now->prev->next = now->next;
            
            if (now->next){
                now->next->prev = now->prev;
                now = now->next;
            }
            else now = now->prev;
        }
        
        if (c[0] == 'Z'){
            node* restore = delete_stack.back();
            delete_stack.pop_back();
            
            if(restore->prev)
                restore->prev->next = restore;
            if(restore->next)
                restore->next->prev = restore;
            
            answer[restore->number] = 'O';
        }  
        
    }  
    return answer;
}