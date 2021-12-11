#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TopVotedCandidate {
public:
	TopVotedCandidate(vector<int>& persons, vector<int>& times) {
		unordered_map<int, int> votes;
		int currLeadingVotes = 0, currLeadingPerson = -1;
		for (size_t t = 0; t < times.size(); t++){
			int currTime = times[t], currPerson = persons[t];
			if (currPerson == currLeadingPerson) {
				votes[currPerson] = ++currLeadingVotes;
			}
			else {
				int currVotes;
				if (votes.find(currPerson) == votes.end()) {
					currVotes = 1;
					votes[currPerson] = 1;
				}
				else {
					currVotes = votes[currPerson] + 1;
					votes[currPerson] = currVotes;
				}

				if (currVotes >= currLeadingVotes){
					leading.push_back(make_pair(currTime, currPerson));
					currLeadingVotes = currVotes;
					currLeadingPerson = currPerson;
				}
			}
		}
	}

	int q(int t) {
		int lo = 0, hi = leading.size() - 1;
		while (lo < hi) {
			int mid = (lo + hi + 1) / 2;
			if (leading[mid].first < t){
				lo = mid;
			}
			else if (leading[mid].first == t){
				return leading[mid].second;
			}
			else {
				hi = mid - 1;
			}
		}
		return leading[lo].second;
	}
private:
	vector<pair<int, int>> leading;
};


int main(void){
	TopVotedCandidate solution = TopVotedCandidate(vector<int>{ 0, 1, 1, 0, 0, 1, 0 }, vector<int> {0, 5, 10, 15, 20, 25, 30});
	cout << solution.q(3) << endl;
	cout << solution.q(12) << endl;
	cout << solution.q(25) << endl;
	cout << solution.q(15) << endl;
	cout << solution.q(24) << endl;
	cout << solution.q(8) << endl;
}
