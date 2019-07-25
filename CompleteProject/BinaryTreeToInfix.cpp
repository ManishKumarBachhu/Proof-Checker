/*
Given a binary tree(as an array - heap implementaion),
it prints out the inoder traversal of the tree with brackets
put at appropriate places.
*/

//#include "GlobalVariables+headers.cpp"    //Dependency if ran independently

void infix(int i, char Arr[], int N)
{
    if(i == 0) printf("(");

    if(Arr[i] == 0)
        return;
    if(Arr[(2*i)+1] == 0 && Arr[(2*i)+2] == 0)
    {
        printf("%c", Arr[i]);
        return;
    }
    else
    {
        if(Arr[(2*i)+1] != 0)
            {
                if(Arr[i] == 'V' || Arr[i] == '^' || Arr[i] == '>')
                    if(Arr[(2*i)+1] == 'V' || Arr[(2*i)+1] == '^' || Arr[(2*i)+1] == '>')
                        printf("(");
                infix((2*i)+1, Arr, N);
            }

        if(Arr[i] == 'V' || Arr[i] == '^' || Arr[i] == '>')
            if(Arr[(2*i)+1] == 'V' || Arr[(2*i)+1] == '^' || Arr[(2*i)+1] == '>')
                printf(")");

        printf("%c", Arr[i]);
        if(Arr[i] == '~')
            if(Arr[2*i+2] == 'V' || Arr[2*i+2] == '^' || Arr[2*i+2] == '>' || Arr[2*i+2] == '~')
                printf("%c", '(');

        if(Arr[(i*2)+2] != 0)
        {
            if(Arr[i] == 'V' || Arr[i] == '^' || Arr[i] == '>')
                if(Arr[(2*i)+2] == 'V' || Arr[(2*i)+2] == '^' || Arr[(2*i)+2] == '>')
                    printf("(");
            infix((2*i)+2, Arr, N);
        }

        if(Arr[i] == 'V' || Arr[i] == '^' || Arr[i] == '>')
            if(Arr[(2*i)+2] == 'V' || Arr[(2*i)+2] == '^' || Arr[(2*i)+2] == '>')
                printf(")");

        if(Arr[i] == '~')
            if(Arr[2*i+2] == 'V' || Arr[2*i+2] == '^' || Arr[2*i+2] == '>' || Arr[2*i+2] == '~')
                printf("%c", ')');
    }
    if(i == 0) printf(")");
}
