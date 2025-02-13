class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result; // Stores the final justified lines
        int n = words.size();  // Total number of words
        int i = 0;             // Starting index for the current line

        while (i < n) {
            int j = i;          // Ending index for the current line
            int lineLength = 0; // Total length of words in the current line
            int wordCount = 0;  // Number of words in the current line

            // Find the words that fit in the current line
            while (j < n && lineLength + words[j].size() + wordCount <= maxWidth) {
                lineLength += words[j].size();
                wordCount++;
                j++;
            }

            int totalSpaces = maxWidth - lineLength; // Total spaces to distribute
            int numGaps = wordCount - 1;            // Number of gaps between words

            string line;

            // If it's the last line or only one word, left-justify
            if (j == n || wordCount == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += ' '; // Add a single space between words
                }
                // Add remaining spaces to the end
                line += string(maxWidth - line.size(), ' ');
            } else {
                // Distribute spaces evenly
                int baseSpaces = totalSpaces / numGaps; // Minimum spaces per gap
                int extraSpaces = totalSpaces % numGaps; // Extra spaces to distribute

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += string(baseSpaces, ' '); // Add base spaces
                        if (extraSpaces > 0) {
                            line += ' '; // Add an extra space
                            extraSpaces--;
                        }
                    }
                }
            }

            result.push_back(line); // Add the justified line to the result
            i = j; // Move to the next line
        }

        return result;
    }
};