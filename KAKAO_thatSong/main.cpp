#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, string> map;
string convert(string str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        if(str[i] == '#')
        {
            str.replace(i - 1, 2, map[str.substr(i - 1, 2)]);
            i--;
        }
    }

    return str;
}
string solution(string m, vector<string> musicInfos)
{
    int max = 0;
    string answer = "(None)";

    map["A#"] = "a";
    map["C#"] = "b";
    map["D#"] = "c";
    map["F#"] = "d";
    map["G#"] = "e";

    m = convert(m);
    for (auto music : musicInfos)
    {
        int startTime   = stoi(music.substr(0, 2)) * 60 + stoi(music.substr(3, 2));
        int endTime     = stoi(music.substr(6, 2)) * 60 + stoi(music.substr(9, 2));
        int musicLength = endTime - startTime;

        music = music.substr(12);

        string songName = music.substr(0, music.find(','));
        string melody   = music.substr(music.find(',') + 1);
        string playedMelody = "";

        melody = convert(melody);
        for (int i = 0; i < musicLength; ++i)
        {
            playedMelody += melody[i % melody.size()];
        }

        if(playedMelody.find(m) != string::npos && endTime - startTime > max)
        {
            answer = songName;
            max    = endTime - startTime;
        }
    }

    return answer;
}