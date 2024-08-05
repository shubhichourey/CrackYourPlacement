/*Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
         vector<string> line;
        int lineSize = 0;
        int cur = 0;
        int n = words.size();
        vector<string> ans;
        
        while(cur < n){
            if(lineSize + (line.size()-1) + (1+words[cur].size()) <= maxWidth){
                lineSize += words[cur].size();
                line.push_back(words[cur]);
                ++cur;
            }else{
                string str = "";
                if(line.size() == 1){
                    str += line[0];
                    str += string(maxWidth - str.size(), ' ');
                }else{
                    int quot = (maxWidth - lineSize)/(line.size()-1);
                    int mod = (maxWidth - lineSize)%(line.size()-1);
                    
                    for(int i = 0; i < line.size(); ++i){
                        str += line[i];
                        if(i != line.size()-1)
                            str += string(quot + (i<mod), ' ');
                    }
                }
                ans.push_back(str);
                line.clear();
                lineSize = 0;
            }
           
        }
        

        string str = "";
        
        for(int i = 0; i < line.size(); ++i){
            str += line[i];
            if(i != line.size()-1) str += " ";
        }
        str += string(maxWidth - str.size(), ' ');
        ans.push_back(str);
        line.clear();
        lineSize = 0;
        
        ans.back() += string(maxWidth-ans.back().size(), ' ');
        
        return ans;
    }
};