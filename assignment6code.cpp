#include <bits/stdc++.h>
using namespace std;
struct HN {
	char data;
	unsigned freq;
	HN *left, *right;
	HN(char data, unsigned freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};
struct compare {
	bool operator()(HN* l, HN* r)
	{
		return (l->freq > r->freq);
	}
};
void printCodes(struct HN* root, string str)
{
	if (!root)
		return;
	if (root->data != '$')
		cout <<root->data << ": " << str << "\n";
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}
void HuffmanCodes(char data[], int freq[], int size)
{
	struct HN *left, *right, *top;
	priority_queue<HN*, vector<HN*>, compare> smallHeap;

	for (int i = 0; i < size; ++i)
		smallHeap.push(new HN(data[i], freq[i]));
	while (smallHeap.size() != 1) {
		left = smallHeap.top();
		smallHeap.pop();
		right = smallHeap.top();
		smallHeap.pop();
		top = new HN('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		smallHeap.push(top);
	}
	printCodes(smallHeap.top(), "");
}
int main()
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HuffmanCodes(arr, freq, size);
	return 0;
}
