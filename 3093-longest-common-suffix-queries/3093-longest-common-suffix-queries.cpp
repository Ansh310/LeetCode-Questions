class Solution {
public:
    struct trienode {
        int idx;
        trienode* children[26];

        ~trienode() {
            for(int i = 0; i < 26; i++) {
                delete children[i];
            }
        }

    };

    trienode* getNode(int i) {
        trienode* temp = new trienode();
        temp->idx = i;

        for(int i = 0; i < 26; i++) {
            temp->children[i] = NULL;
        }

        return temp;
    }

    void insertTrie(trienode* root, int i, vector<string>& wordsContainer) {
        string word = wordsContainer[i];

        int n = word.length();

        for(int j = n - 1; j >= 0; j--) {
            char ch = word[j];
            int ch_idx = ch - 'a';

            if(root->children[ch_idx] == NULL) {
                root->children[ch_idx] = getNode(i);
            }

            root = root->children[ch_idx];

            if(wordsContainer[root->idx].length() > n) {
                root->idx = i;
            }
        }
    }

    int searchTrie(trienode* root, string& word) {
        int result_idx = root->idx;
        int n = word.length();

        for(int i = n - 1; i >= 0; i--) {
            int ch_idx = word[i] - 'a';

            root = root->children[ch_idx];
            if(root == NULL) {
                return result_idx;
            }

            result_idx = root->idx;
        }

        return result_idx;
    }
    
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m = wordsContainer.size();
        int n = wordsQuery.size();

        vector<int> result(n);

        trienode* root = getNode(0);

        for(int i = 0; i < m; i++) {
            int idx = root->idx;
            if(wordsContainer[idx].length() > wordsContainer[i].length()) {
                root->idx = i;
            }
            insertTrie(root, i, wordsContainer);
        }

        for(int i = 0; i < n; i++) {
            result[i] = searchTrie(root, wordsQuery[i]);
        }

        delete root;
        return result;
    }
};