#ifndef BSTREE_HPP
#define BSTREE_HPP

#include <iostream>
#include <queue>
#include <functional>
#include <stack>
class BSTree
{
public:
	typedef int DataType;
	typedef std::function<void(DataType)> AccType;
private:
	struct BSNode
	{
		DataType data;
		BSNode* lchild;
		BSNode* rchild;
		BSNode(DataType d) : data(d), lchild(nullptr), rchild(nullptr)
		{
		}
		~BSNode()
		{
#ifndef NDEBUG
			std::cout << "~BSNode() data = " << data << std::endl;
#endif
		}
	};
public:
	void insert(DataType d)
	{
		BSNode* tmp = new BSNode(d);
		treeSize++;
		if(nullptr == root) {
			root = tmp;
			return;
		}
		BSNode* p = nullptr;
		BSNode* q = root;
		while(q != nullptr) {
			p = q;
			if(d > q->data) {
				q = q->rchild;
			}
			else {
				q = q->lchild;
			}
		}
		if(d > p->data) {
			p->rchild = tmp;
		}
		else {
			p->lchild = tmp;
		}
	}
	BSTree() : treeSize(0), root(nullptr)
	{
	}
	BSTree(std::istream& ist)
	{
		DataType d;
		while(ist >> d) {
			insert(d);
		}
	}
	~BSTree()
	{
		std::queue<BSNode*> nodeQueue;
		if(nullptr != root) {
			nodeQueue.push(root);
		}
		while(!nodeQueue.empty()) {
			auto head = nodeQueue.front();
			if(nullptr != head->lchild) {
				nodeQueue.push(head->lchild);
			}
			if(nullptr != head->rchild) {
				nodeQueue.push(head->rchild);
			}
			nodeQueue.pop();
			delete head;
		}
	}
	void midIter(AccType& f)
	{
		std::stack<BSNode*> st;
		auto p = root;
		while(nullptr != p || !st.empty()) {
			while(nullptr != p) {
				st.push(p);
				p = p->lchild;
			}
			if(!st.empty()) {
				p = st.top();
				f(p->data);
				st.pop();
				p = p->rchild;
			}
		}
	}
	void prevIter(AccType& f)
	{
		std::stack<BSNode*> st;
		auto p = root;
		while(nullptr != p || !st.empty()) {
			f(p->data);
			st.push(p);
			p = p->lchild;
			while(nullptr == p && !st.empty()) {
				p = st.top();
				st.pop();
				p = p->rchild;
			}
		}
	}
private:
	int treeSize;
	BSNode* root;
};
#endif
