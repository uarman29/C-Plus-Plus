#include <cstdio>   // printf
#include <cstdlib>  // rand
#include <time.h>   // time
#include <getopt.h> // to parse long arguments.
#include <stdlib.h>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
#include <algorithm>
using std::swap;
using std::min;
using std::to_string;

static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Limited clone of shuf.  Supported options:\n\n"
"   -e,--echo              treat each argument as an input line.\n"
"   -i,--input-range=LO-HI treat each number in [LO..HI] as an input line.\n"
"   -n,--head-count=N      output at most N lines.\n"
"   --help                 show this message and exit.\n";
void printVector(vector<string> v)
{
	for(size_t i=0;i<v.size()-1;i++)
	{
		cout<< v[i]<<", ";
	}
	cout<<v[v.size()-1]<<"\n";
}

int getRan(int lower,int upper)
{
	srand(time(0));
	return rand()%upper+lower;
}

void removeElement(vector<string> &v, int index)
{
	string temp = v[index];
	v[index] = v[v.size()-1];
	v[v.size()-1] = temp;
	v.pop_back();
}

void shuf(vector<string> &input)
{
	vector<string> shuffled;
	int r;
	for(int i=input.size()-1;i>0;i--)
	{
		r = getRan(0,i);
		shuffled.push_back(input[r]);
		removeElement(input,r);

	}
	shuffled.push_back(input[0]);
	input = shuffled;
}


int main(int argc, char *argv[]) {
	// define long options
	static int echo=0, rlow=0, rhigh=0;
	static size_t count=-1;
	bool userange = false;
	static struct option long_opts[] = {
		{"echo",        no_argument,       0, 'e'},
		{"input-range", required_argument, 0, 'i'},
		{"head-count",  required_argument, 0, 'n'},
		{"help",        no_argument,       0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "ei:n:h", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'e':
				echo = 1;
				break;
			case 'i':
				if (sscanf(optarg,"%i-%i",&rlow,&rhigh) != 2) {
					fprintf(stderr, "Format for --input-range is N-M\n");
					rlow=0; rhigh=-1;
				} else {
					userange = true;
				}
				break;
			case 'n':
				count = atol(optarg);
				break;
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	}
	/* NOTE: the system's shuf does not read stdin *and* use -i or -e.
	 * Even -i and -e are mutally exclusive... */

	/* TODO: write me... */
	string s;
	vector<string> input;
	if(userange)
	{
		for(int i=rlow;i<=rhigh;i++)
		{
			input.push_back(to_string(i));
		}
	}
	else
	{
		if(echo)
		{
			while(optind<argc)
			{
				input.push_back(argv[optind++]);
			}
		}
		else
		{
			while(getline(cin,s))
			{
				input.push_back(s);
			}
		}
	}
	if(input.size()==0)
	{
		return 0;
	}
	shuf(input);
	if(count!=-1)
	{
		for(size_t i=0;i<count;i++)
		{
			cout<<input[i]<<"\n";
		}
	}
	else
	{
		for(size_t i=0;i<input.size();i++)
		{
			cout<<input[i]<<"\n";
		}
	}
	return 0;
}



