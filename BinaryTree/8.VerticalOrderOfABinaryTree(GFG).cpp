// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    
    class Pair {
        public:
        Node * node;
        int d;
        int w;
        Pair(Node * node , int w , int d) {
            this->node = node;
            this->d = d;
            this->w = w;
        }
    };
    
    vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<Pair> q;
        q.push(Pair(root , 0 , 1));
        map<int , vector<Pair>> map;
        int lw = 0;
        int rw = 0;
        while(q.size() > 0) {
            Pair front = q.front();
            q.pop();
            
            if(front.w < lw) {
                lw = front.w;
            }
            if(front.w > rw){
                rw = front.w;
            }
            
            map[front.w].push_back(front);
            
            if(front.node->left != NULL){
                q.push(Pair(front.node->left , front.w - 1 , front.d + 1));
            }
            if(front.node->right != NULL) {
                q.push(Pair(front.node->right , front.w + 1 , front.d + 1));
            }
            
        }
        
        for(int i = lw ; i <= rw ; i++){
            vector<Pair> partOfAns = map[i];
            for(Pair temp : partOfAns){
                ans.push_back(temp.node->data);
            }
        }
        return ans;
    }
};



// { Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}


  // } Driver Code Ends