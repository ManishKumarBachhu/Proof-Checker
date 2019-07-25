/*
Given an input as a string it converts the string
into postfix and updates the global stack "ans" with the postfix order.

Remember before using the postfix function the stack must be empty.
*/


//#include "GlobalVariables+headers.cpp"   //Dependency if ran independently

void postfix(string s)
{
	int flag = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if(!(s[i] > 96 and s[i] < 123) or s[i] == 'V')
		{
			op.push(s[i]);
			if(s[i] == '~')
				flag++;
			else flag = 0;
			if(op.top() == ')')
			{
				op.pop();
				while(op.top() != '(')
				{
					if(op.top() != ')' and op.top() != '~')
						ans.push(op.top());
					op.pop();
				}
				op.pop();
				while(!op.empty() and (op.top() == '~'))
					ans.push(op.top()),op.pop();
				continue;
			}
		}
		else
		{
			ans.push(s[i]);
			if(flag >= 1)
				while(flag--)
					ans.push(op.top()),op.pop();
		}
	}
	while(!op.empty())
	{
		ans.push(op.top());
		op.pop();
	}
}
