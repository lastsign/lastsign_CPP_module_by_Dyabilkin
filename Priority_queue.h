#ifndef Priority_queue_H
#define Priority_queue_H
void error_msg(bool a);
class Priority_Queue
{
private:
	int* a;
	int k;
	int qSize;
public:
	Priority_Queue(int);
	~Priority_Queue();
	void push(int);
	void pop();
	const int& top();
	int size();
	bool empty();
};
#endif 
