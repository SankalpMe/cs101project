//
// Created by sankalp on 27/02/21.
//

#include "HighScoreData.h"

void HighScoreData::loadEntries(){

    ifstream fin("score.dat",ios::in);

    //check if file read failed
    if(fin.fail()){
        cerr << "failed to open score file (score.dat)" << endl;
        entries =  vector<ScoreEntry>(0);
        return;
    }
    size_t n;
    fin >> n; // no of entries in file
    if(fin.fail()){
        cerr << "failed to open score file (score.dat)" << endl;
        entries =  vector<ScoreEntry>(0);
        return;
    }
    fin.get();
    entries =  vector<ScoreEntry>(n);

    // deserialize the entries stored in the file
    for(auto &e: entries){
        char istr[257];

        fin.getline(istr,256);
        e.name = string(istr,istr+strlen(istr));
        fin >> e.score;
        fin.get();
    }


    fin.close();
}

void HighScoreData::saveEntries(){
    sortEntry();
    ofstream fout("score.dat",ios::out|ios::trunc);


    if(fout.fail()){
        cerr << "failed to open score file" << endl;
        exit(0);
    }
    size_t entrySize = entries.size();

    fout << entrySize << endl;

    //serialize the entries into the file
    for(auto &e: entries){
        fout << e.name << endl;
        fout <<  e.score << endl;
    }
    fout.close();
}


void HighScoreData::addEntry(string name,double  score){
    // add entry to entries , if entry already exists update it to highest.

    for(auto &en: entries){
        if(en.name == name){
            if(en.score < score){
                en.score = score; // update existing entry if new highscore is found
            }
            return;
        }
    }
    entries.push_back({name,score}); // add if no previous entry found
}