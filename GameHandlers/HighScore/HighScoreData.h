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

public:
    vector<ScoreEntry> entries;
    HighScoreData(){
        loadEntries();
    }
    void addEntry(string name,double  score){
        // add entry to entries , if entry already exists update it to highest.

        for(auto &en: entries){
            if(en.name == name){
                if(en.score < score){
                    en.score = score;
                }
                return;
            }
        }
        entries.push_back({name,score});
    }
    const vector<ScoreEntry> &getList(){
        return entries;
    }
    void sortEntry(){
        sort(entries.begin(),entries.end(),[](const ScoreEntry &le,const ScoreEntry &re)->bool {
            return  (le.score > re.score )|| (le.score == re.score && le.name > re.name);
        });
    }
    void saveEntries(){
        sortEntry();
        ofstream fout("score.dat",ios::out|ios::trunc);
        if(fout.fail()){
            cerr << "failed to open score file" << endl;
            exit(0);
        }
        size_t entrySize = entries.size();

        fout << entrySize << endl;

        for(auto e: entries){
            fout << e.name << endl;
            fout <<  e.score << endl;
        }
        fout.close();
    }

    void loadEntries(){

        ifstream fin("score.dat",ios::in);
        if(fin.fail()){
            cerr << "failed to open score file (score.dat)" << endl;
            entries =  vector<ScoreEntry>(0);
            return;
        }
        size_t n;
        fin >> n;
        if(fin.fail()){
            cerr << "failed to open score file (score.dat)" << endl;
            entries =  vector<ScoreEntry>(0);
            return;
        }
        fin.get();
        entries =  vector<ScoreEntry>(n);

        for(auto &e: entries){
            char istr[257];

            fin.getline(istr,256);
            e.name = string(istr,istr+strlen(istr));
            fin >> e.score;
            fin.get();
        }


        fin.close();
    }
};


#endif //LASSOPROJECT_HIGHSCOREDATA_H
