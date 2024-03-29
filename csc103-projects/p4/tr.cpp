/*
 * CSc103 Project 3: unix utilities
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours:
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
#include <string.h> // for c-string functions.
#include <getopt.h> // to parse long arguments.

static const char* usage =
"Usage: %s [OPTIONS] SET1 [SET2]\n"
"Limited clone of tr.  Supported options:\n\n"
"   -c,--complement     Use the complement of SET1.\n"
"   -d,--delete         Delete characters in SET1 rather than translate.\n"
"   --help          show this message and exit.\n";

void escape(string& s) {
	/* NOTE: the normal tr command seems to handle invalid escape
	 * sequences by simply removing the backslash (silently) and
	 * continuing with the translation as if it never appeared. */
	/* TODO: write me... */
	string str="";
	for(size_t i=0;i<s.length();i++)
	{
		if(s[i]!=92)
		{
			str+=s[i];
		}
		else
		{
			if(i+1 != s.length()&&(s[i+1]=='n'||s[i+1]=='t'||s[i+1]=='\\'))
			{
				str +=s[i];
				str +=s[i+1];
				i++;
			}
		}
	}
	s = str;
}
int inString(string s,char c)
{
	for(size_t i=0;i<s.length();i++)
	{
		if(s[i]==c)
		{
			return i;
		}
	}
	return -1;
}
void removeChar(string &s,char c)
{
	string s1 ="";
	for(size_t i=0;i<s.size();i++)
	{
		if(s[i]!=c)
		{
			s1 += s[i];
		}
	}
	s = s1;
}

int main(int argc, char *argv[])
{
	// define long options
	static int comp=0, del=0;
	static struct option long_opts[] = {
		{"complement",      no_argument,   0, 'c'},
		{"delete",          no_argument,   0, 'd'},
		{"help",            no_argument,   0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "cdh", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'c':
				comp = 1;
				break;
			case 'd':
				del = 1;
				break;
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	}
	if (del) {
		if (optind != argc-1) {
			fprintf(stderr, "wrong number of arguments.\n");
			return 1;
		}
	} else if (optind != argc-2) {
		fprintf(stderr,
				"Exactly two strings must be given when translating.\n");
		return 1;
	}
	string s1 = argv[optind++];
	string s2 = (optind < argc)?argv[optind]:"";
	/* process any escape characters: */
	escape(s1);
	escape(s2);
	string s;
	string str = "";
	/* TODO: finish this... */
	if(del)
	{
		if(!comp)
		{
			while(getline(cin,s))
			{
				for(size_t i=0;i<s1.size();i++)
				{
					if(inString(s,s1[i])!=-1)
					{
						removeChar(s,s1[i]);
					}
				}
				cout<<s<<"\n";
			}
		}
		else
		{
			while(getline(cin,s))
			{
				for(size_t i=0;i<s1.size();i++)
				{
					if(inString(s,s1[i])!=-1)
					{
						str += s1[i];
					}
				}
			}
			cout<<str;
		}
	}
	else
	{
		int at;
		if(!comp)
		{
			while(getline(cin,s))
			{
				for(size_t i=0;i<s.length();i++)
				{
					at = inString(s1,s[i]);
					if(at!=-1)
					{
						if(at>(s2.size()-1))
						{
							s[i] = s2[s2.size()-1];
						}
						else
						{
							s[i] = s2[at];
						}
					}
				}
				cout<<s<<"\n";
			}
		}
		else
		{
			while(getline(cin,s))
			{
				for(size_t i=0;i<s.length();i++)
				{
					at = inString(s1,s[i]);
					if(at==-1)
					{
						str += s2[s2.size()-1];
					}
					else
					{
						str += s[i];
					}
				}
			}
		}
		cout<<str;
	}
	return 0;
}




