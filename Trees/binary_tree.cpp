#include <iostream>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

template <typename T>
class BinaryTree
	{
		public:

			class Node
				{
					public:
						Node *lchild;
						T data;
						Node *rchild;
						Node(T x, Node *l = NULL, Node *r = NULL): data(x), lchild(l), rchild(r) {};			
				} *root;

			void create()
				{
					queue<Node *> q;
					T x;
					Node *p, *t;
					
					cout << "\nEnter root element: ";
					cin >> x;
					
					p = new Node(x, 0, 0);
					root = p;
					q.push(p);

					while(!q.empty())
						{
							p = q.front();
							q.pop();
							
							cout << "\nEnter left child element of " << p -> data << ": ";
							cin >> x;
							
							if(x != -1)
								{
									t = new Node(x, 0, 0);
									p->lchild = t;
									q.push(t);
								}
							
							cout << "\nEnter right child element of " << p -> data << ": ";
							cin >> x;
							
							if(x != -1)
								{
									t = new Node(x, 0, 0);
									p->rchild = t;
									q.push(t);
								}
						}
				}

			void r_preorder(Node *p)
				{
					if(p)
						{
							cout << p->data << " ";
							r_preorder(p->lchild);
							r_preorder(p->rchild);	
						}
				}

			void r_inorder(Node *p)
				{
					if(p)
						{
							cout << p->data << " ";
							r_inorder(p->lchild);
							r_inorder(p->rchild);	
						}
				}

			void r_postorder(Node *p)
				{
					if(p)
						{
							cout << p->data << " ";
							r_postorder(p->lchild);
							r_postorder(p->rchild);	
						}
				}

			void preorder()
				{
					Node *t = root;
					stack<Node*> s;
					
					cout << endl;

					while(t || !s.empty())
						{
							if(t)
								{
									cout << t->data << " ";
									s.push(t);
									t = t->lchild;
								}
							else
								{
									t = s.top();
									s.pop();
									t = t -> rchild;
								}
						}
					
					cout << endl;
				}

			void inorder()
				{
					Node *t = root;
					stack<Node*> s;
					
					cout << endl;

					while(t || !s.empty())
						{
							if(t)
								{
									s.push(t);
									t = t->lchild;
								}
							else
								{
									t = s.top();
									s.pop();
									cout << t->data << " ";
									t = t -> rchild;
								}
						}
					
					cout << endl;
				}

			void postorder()
				{
					Node *t = root;
					stack<pair<Node*, bool>> s;
					pair<Node*, bool> temp_pair;
					
					cout << endl;

					while(t || !s.empty())
						{
							if(t)
								{
									s.push({t, true});
									t = t->lchild;
								}
							else
								{
									temp_pair = s.top();
									s.pop();
									if(temp_pair.second)
										{
											s.push({temp_pair.first, !temp_pair.second});
											t = temp_pair.first->rchild;
										}
									else
											cout << temp_pair.first->data << " ";
								}
						}
					
					cout << endl;
				}		

			void levelorder()
				{
					queue<Node *> q;
					Node *t = root;
					
					cout << '\n' << t->data << " ";
					
					q.push(t);
					while(!q.empty())
						{
							t = q.front();
							q.pop();

							if(t->lchild)
								{
									cout << t->lchild->data << " ";
									q.push(t->lchild);
								}
							
							if(t->rchild)
								{
									cout << t->rchild->data << " ";
									q.push(t->rchild);
								}
						}

					cout << endl;
				}						

			int r_count(Node *p)
				{
					if(p)
						return r_count(p->lchild) + r_count(p->rchild) + 1;
					return 0;
				}

			T r_sum(Node *p)
				{
					if(p)
						return r_sum(p->lchild) + r_sum(p->rchild) + p->data;
					return 0;
				}

			int r_level(Node *p)
				{
					if(p)
						{
							int l = r_level(p->lchild);
							int r = r_level(p->rchild);
							if(l < r)
								return r + 1;
							else
								return l + 1;
						}
					return 0;	
				}

			// Degree 0 
			int r_internal(Node *p)
				{
					if(p)
						{
							int l = r_internal(p->lchild);
							int r = r_internal(p->rchild);
							if(!p->lchild && !p->lchild)
								return l + r + 1;
							return l + r;
						}
					return 0;
				}

			// Degree 1 or 2 
			int external(Node *p)
				{
					return count(p) - r_internal(p);
				}

			// Degree 1 
			int r_degree1(Node *p)
				{
					if(p)
						{
							int l = r_internal(p->lchild);
							int r = r_internal(p->rchild);
							if(!p->lchild ^ !p->lchild)
								return l + r + 1;
							return l + r;
						}
					return 0;
				}

			// Degree 2 
			int r_degree2(Node *p)
				{
					if(p)
						{
							int l = r_degree2(p->lchild);
							int r = r_degree2(p->rchild);
							if(p->lchild && p->lchild)
								return l + r + 1;
							return l + r;
						}
					return 0;
				}
};

int main()
	{
		BinaryTree<int> t1;
		t1.create();
		cout << '\n';
		t1.preorder();
		t1.inorder();
		t1.postorder();
		t1.levelorder();
		cout << "\nLevel: " << t1.r_level(t1.root);
		cout << "\nSum: " << t1.r_sum(t1.root);
		cout << "\nCount: " << t1.r_count(t1.root);
		cout << endl;
		return 0;
	}
