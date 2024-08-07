#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node
{
	int endmarker;
	struct Node* arr[26];
};

class trie
{
public:
	Node* Root;

	trie()
	{	
		Root = (Node*)malloc(sizeof(struct Node) * 1);
		Root->endmarker = 0;
		for(int i = 0; i < 26; i++)
		{
			Root->arr[i] = nullptr;
		}
	}

	void insert(string& word)
	{
		int length = word.length();
		Node* ref = Root;
		if(ref == nullptr){std::cout << "Hell" << std::endl;}
		for(int i = 0; i < length; i++)
		{	
			
			if(ref->arr[word[i] - 'a'] == nullptr)
			{	

				ref->arr[word[i] - 'a'] = (Node*)malloc(sizeof(struct Node) * 1);
				ref->arr[word[i] - 'a']->endmarker = 0;
				for(int j = 0; j < 26; j++)
				{
					ref->arr[word[i] - 'a']->arr[j] = nullptr;
				}
			}

			ref = ref->arr[word[i] - 'a'];
		}
		ref->endmarker = 1;
	}

	vector<int> search(string& word, int j)
	{
		int length = word.length() - j;
		Node* ref = Root;
		vector<int> x;
		for(int i = 0; i < length; i++)
		{	
			if(ref->arr[word[j + i] - 'a'] == NULL)
			{
				break;
			}
			ref = ref->arr[word[j + i] - 'a'];
			if(ref->endmarker == 1)
			{
				x.push_back(i + 1);
			}
		}

		return x;
	}
};

int main()
{
	string s;
	std::getline(std::cin, s);
	int k;
	std::cin >> k;
	int n = s.length();
	string temp;
	std::getline(std::cin, temp);

	trie x;
	for(int i = 0; i < k; i++)
	{
		std::getline(std::cin, temp);
		x.insert(temp);
	}

	long long int* arr = new long long int[s.length() + 1];
	arr[s.length()] = 1;
	for(int i = n - 1; i >= 0; i--)
	{	
		long long int count = 0;
		vector<int> y = x.search(s, i);
		for(auto ele : y)
		{
			count += arr[i + ele];
			count = count % 1000000007; 
		}
		arr[i] = count;
	}

	std::cout << arr[0];
}