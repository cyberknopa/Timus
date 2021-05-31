#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int comp1 (pair<int, int>primo, pair<int, int>secondo){
    if(primo.first == secondo.first)
        return(primo.second < secondo.second);
    else
        return (primo.first < secondo.first);
}

int comp2 (pair<int, int>primo, pair<int, int>secondo){
    if(primo.second == secondo.second)
        return(primo.first<secondo.first);
    else
        return (primo.second<secondo.second);
}

int main(){

    int lef , righ;
    int point = 0;
    int M;
    vector <pair<int, int>> segments;
    vector <pair<int, int>> segments_done;
    int max_second = 0;
    pair<int, int> max_segment;
    int end_of_segment;
    cin >> M;
    for(;;) {
        cin >> lef;
        cin >> righ;
        if (lef == 0 && righ == 0) {
            break;
        } else
            segments.push_back(make_pair(lef, righ));
    }

    sort(segments.begin(), segments.end(), comp1);
    max_second=0;
    max_segment = segments[0];
    for(int i = 0; i < segments.size(); i++){
        if(segments[i].first > point){
            if(max_second<segments[i].first)
                break;
            segments_done.push_back(max_segment);
            point = max_second;
        }
        if(segments[i].second > max_second){
            max_second = segments[i].second;
            max_segment = segments[i];
            if(max_second >= M){
                segments_done.push_back(max_segment);
                break;
            }
        }
    }
    if(max_second<M)
        cout << "No solution"<<'\n';
    else{
        cout<< segments_done.size()<<'\n';
        for(int i=0; i<segments_done.size(); i++){
            cout<< segments_done[i].first <<'\n';
            cout<< segments_done[i].second <<'\n';
        }

    }
}
