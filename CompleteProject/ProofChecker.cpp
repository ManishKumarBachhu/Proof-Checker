/*
Propositional Logic Proof Checker for rules:
And Introduction(^i)
And Elimination1(^e1)
And Elimination2(^e2)
Or  Introduction1(Vi1)
Or  Introduction2(Vi2)
Implication Elimination(>e)
Modus Tollens(MT)

Takes proof as input (input as strings of well-formed propositional formula,
proof rules and line numbers(if required))
and prints whether the proof is valid or invalid.
*/


#include "GlobalVariables+headers.cpp"
#include "InputToPostfix.cpp"
#include "PostfixToBinaryTree.cpp"
#include "BinaryTreeToInfix.cpp"
#include "Matching2Trees.cpp"
#include "ProofRuleFunctions.cpp"


int main()
{
	IOS;
	int n;
    cin>>n;

	string s[n];
    string rule[n];
    int d[n][2];
    int i = 0,z=0;
    for(i = 0; i < n; i++,z=0)
    {
        char c;
		//string input
        scanf("\n%c", &c);
        while(c != '/')
        {
            string p(1,c);
            s[i].append(p);
            scanf("%c",&c);
        }

		postfix(s[i]);

		char *heap1 = tree(ans);

		for(int j=0; j<Z; j++)
			D2[i][j] = *(heap1+j);

		while(!ans.empty())
			ans.pop();

		//rule input
        scanf("%c",&c);
        while(c != '/')
        {
            string p(1,c);
            rule[i].append(p);
            if(c == 'P')
                break;
            scanf("%c",&c);
        }
		//numbers input
        scanf("%c", &c );
        while(c != '\n')
        {
            if(c != '/')
                d[i][z++] = c-'0';
            scanf("%c",&c);
        }
    }

	for(int i=0; i<n; i++)
	{
		if(rule[i] == "P")
			continue;
		else if(rule[i] == "^i")
		{
			bool truth = AndI(D2[i], d[i][0], d[i][1]);

			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}
		else if(rule[i] == "^e1")
		{
			bool truth = AndE(D2[i], 1, d[i][0]);

			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}
		else if(rule[i] == "^e2")
		{
			bool truth = AndE(D2[i], 2, d[i][0]);

			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}
		else if(rule[i] == "Vi1")
		{
			bool truth = OrI(D2[i], 1, d[i][0]);

			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}
		else if(rule[i] == "Vi2")
		{
			bool truth = OrI(D2[i], 2, d[i][0]);

			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}
		else if(rule[i] == ">e")
		{
			bool truth = ImpE(D2[i], d[i][0], d[i][1]);

			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}
		else if(rule[i] == "MT")
		{
			bool truth = MT(D2[i], d[i][0], d[i][1]);

			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}
	}
	printf("Valid Proof");

    return 0;
}
