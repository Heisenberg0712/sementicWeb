#include<bits/stdc++.h>
using namespace std;


void updatePairs(map<string,string>& sarcasticPairs){
	sarcasticPairs["won"]="joke";
	sarcasticPairs["won"]="lost";
	sarcasticPairs["admin"]="lack";
	sarcasticPairs["alot"]="poverty";
	sarcasticPairs["years"]="poverty";
	//example of some pair of words that are often use on twitter to convey disapproval or sarcasm
}

void tweetDelimiter(string s,vector<string>& tweet_split)
{
    stringstream ss(s);
    string word;
    while (ss >> word) {
        tweet_split.push_back(word);
    }
}

bool checkIfTheTweetIsPolitical(vector<string> tweet_split, string word){

	for(auto itr  : tweet_split){
		if(word==itr){
			return true;
		}
	}
	return false;
}

bool checkForTheOtherWordOfSarcasticPair(vector<string> tweet_split, string word){

	for(auto itr : tweet_split){
		if(word==itr){
			return true; //sarcasm exist
		}
	}
	return false; // sarcasm does not exists, it is a serious!!!!! tweet
}

bool checkForTheFirstWordOfSarcasticPair(vector<string> tweet_split,string word){
	for(auto itr : tweet_split){
		if(word==itr){
			return true;
		}
	}
	return false;
}

int checkScoreOfTweet(vector<string> tweet_split, string hashtag, int peopleTalking){
	int score=0;
	for(auto itr : tweet_split){
		if(itr==hashtag){
			score+=peopleTalking;
		}
	}
	return score;
}

 main(){
	static string arr[9] = {"democracy","win","dialogue","election","house","parliament","majority","minority","government"};
	//Example of metadata of political words in english vocabulary

	map<string,string> sarcasticPairs;
	updatePairs(sarcasticPairs);

	//

	vector<pair<string,int>> trending_hashtags;
	trending_hashtags.push_back(make_pair("elections",50));
	trending_hashtags.push_back(make_pair("donaldTrump",100));
	trending_hashtags.push_back(make_pair("america",150));
	trending_hashtags.push_back(make_pair("blackLivesMatter",125));
	trending_hashtags.push_back(make_pair("RamMandir",127));

	// example of political hashtags

	string tweet;

	cout<<"Enter the tweet \n";
	cin>>tweet;

	vector<string> tweet_split;
	tweetDelimiter(tweet,tweet_split);

	int threshold=120;

	bool isTheTweetPolitical=false;

	for(int i=0;i<9;i++){
		if(checkIfTheTweetIsPolitical(tweet_split,arr[i])){
			isTheTweetPolitical=true;
			break;
		}
	}

	if(isTheTweetPolitical==false){
		return 0; //if the tweet is not political then program ends here
	}

	bool sarcasmExist=false;
	for(auto itr : sarcasticPairs){
		if(checkForTheFirstWordOfSarcasticPair(tweet_split,itr.first)){
			if(checkForTheOtherWordOfSarcasticPair(tweet_split,itr.second)){
				sarcasmExist=true;
				break;
			}
		}
	}

	if(sarcasmExist==true){
		return 0; //program ends her as sarcasm exist in the tweet
	}

	// if program does not end then it means that sarcasm does not exists and tweet is serious!!!!!

	int score=0;

	for(auto itr : trending_hashtags){
		score+=checkScoreOfTweet(tweet_split,itr.first,itr.second);
	}

	if(score>threshold){
		cout<<"Tweet seems legit and is safe for the community";
	}
	else{
		cout<<"Tweet does seem legit and can lead to chaos in society";
	}

	return 0;



}