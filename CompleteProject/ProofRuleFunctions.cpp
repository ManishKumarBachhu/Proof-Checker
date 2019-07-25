/*
Contains functions one for each proof rule.
Returns true if rule applys correctly,
otherwise returns false.
*/


//#include "GlobalVariables+headers.cpp"    //Dependency if ran independently
//#include "Matching2Trees.cpp"             //Dependency if ran independently

bool AndI(char tree[], int l1, int l2)
{
    if(tree[0] != '^') return false;
    if(MatchTree(tree, D2[l1-1], 1, 0) && MatchTree(tree, D2[l2-1], 2, 0))  /// 0->start from root// 1->left // 2->right
        return true;
    else
		return false;
}

bool AndE(char tree[], int type, int l1)
{
    if(D2[l1-1][0] != '^') return false;
    if(type == 1)
        if(MatchTree(tree, D2[l1-1], 0, 1))
            return true;
    if(type == 2)
        if(MatchTree(tree, D2[l1-1], 0, 2))
            return true;

    return false;
}

bool OrI(char tree[], int type, int l1)
{
    if(tree[0] != 'V') return false;
    if(type == 1)
        if(MatchTree(tree, D2[l1-1], 1, 0))
            return true;
    if(type == 2)
        if(MatchTree(tree, D2[l1-1], 2, 0))
            return true;

    return false;
}

bool ImpE(char tree[], int l1, int l2)
{
    if(D2[l1-1][0] != '>') return false;
    if(MatchTree(D2[l1-1], D2[l2-1], 1, 0) && MatchTree(D2[l1-1], tree, 2, 0))
        return true;

    return false;
}

bool MT(char tree[], int l1, int l2)
{
    if(D2[l1-1][0] != '>') return false;

    if(tree[0] != '~' || D2[l2-1][0] != '~') return false;

    if(MatchTree(tree, D2[l1-1], 2, 1) && MatchTree(D2[l2-1], D2[l1-1], 2, 2))
        return true;
    else
        return false;
}
