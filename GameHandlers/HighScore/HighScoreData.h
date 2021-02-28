//
// Created by sankalp on 27/02/21.
//

#ifndef LASSOPROJECT_HIGHSCOREDATA_H
#define LASSOPROJECT_HIGHSCOREDATA_H

#include <vector>

#include <fstream>
#include <simplecpp>
#include <stdlib.h>
#include <algorithm>
struct ScoreEntry{
    string  name;
    double score;
};

class HighScoreData {
    vector<ScoreEntry> entries; // memory buffer for all the score entries
public:
    HighScoreData(){
        loadEntries();
    }
    void addEntry(string name,double  score); // adds the new highscore entry to memory buffer

    const vector<ScoreEntry> &getList(){ return entries; } // returns the entries buffer

    void saveEntries(); // save the entries of memory buffer to file 'score.dat'

    void loadEntries(); // load the entries of 'score.dat' into the memory buffer.

    // a util function to sort the inserted entries in descending order
    void sortEntry(){
        sort(entries.begin(),entries.end(),[](const ScoreEntry &le,const ScoreEntry &re)->bool {
            return  (le.score > re.score )|| (le.score == re.score && le.name > re.name);
        });
    }
};


#endif //LASSOPROJECT_HIGHSCOREDATA_H
