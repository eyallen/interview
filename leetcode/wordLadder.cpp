#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

void addNextWords(string word, unordered_set<string>& list, queue<string>& q)
{
    list.erase(word);

    for (int i = 0; i < word.length(); ++i)
    {
        char c = word[i];

        // Shift the character
        for (int j = 0; j < 26; ++j)
        {
            word[i] = 'a' + j;
            if (list.find(word) != list.end())
            {
                q.push(word);
                list.erase(word);
            }
        }

        word[i] = c;
    }
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
    unordered_set<string> list;

    // We want constant time lookup of unique words, so add wordList to an unordered_set
    for (string str : wordList)
    {
        list.insert(str);
    }

    queue<string> q;
    addNextWords(beginWord, list, q);
    int length = 2;

    while(!q.empty())
    {
        int size = q.size(); // Only process the current queue before adding length
        for (int i = 0; i < size; i++)
        {
            // See if we have a transformation in the list of words
            string word = q.front();
            q.pop();

            if (word == endWord)
            {
                return length;
            }

            addNextWords(word, list, q);
        }
        
        length++;
    }

    return 0;
}

int main()
{
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << ladderLength("hit", "cog", wordList) << endl;
    cout << ladderLength("hit", "dot", wordList) << endl;
    cout << ladderLength("hit", "not", wordList) << endl;
}