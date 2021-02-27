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
    vector<ScoreEntry> entries;
public:
    void addEntry(string name,double  score){
        // add entry to entries , if entry already exists update it to highest.

        for(auto en: entries){
            if(en.name == name){
                if(en.score < score){
                    en.score = score;
                }
                return;
            }
        }
    }
    const vector<ScoreEntry> &getList(){
        return entries;
    }
    void sortEntry(){
        sort(entries.begin(),entries.end(),[](const ScoreEntry &le,const ScoreEntry &re)->bool {
            return  (le.score < re.score )|| (le.score == re.score && le.name < re.name);
        });
    }
    void saveEntries(){
        sortEntry();
        ofstream fout("score.dat",ios::binary|ios::out);
        if(fout.fail()){
            cerr << "failed to open score file" << endl;
            exit(0);
        }
        size_t entrySize = entries.size();

        fout.write( (char*) &entrySize,sizeof(entrySize));

        for(int i = 0 ; i < entries.size() ;i++){
            fout.write((char *) &entries[i],sizeof (ScoreEntry));
        }
        fout.close();
    }

    void loadEntries(){

        ifstream fin("score.dat",ios::binary|ios::in);
        if(fin.fail()){
            cerr << "failed to open score file (score.dat)" << endl;
            return;
        }
        size_t n;
        fin.read((char *) &n,sizeof(n));
        entries =  vector<ScoreEntry>(n);

        for(int i = 0 ;i  < n;i++){
            fin.read((char *)&entries[i],sizeof (ScoreEntry));
        }
        fin.close();
    }
};


#endif //LASSOPROJECT_HIGHSCOREDATA_H
