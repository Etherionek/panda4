#include "BTree.h"

BTree::BTree() {
    root = nullptr;
}

void BTree::~BTree() {}


void BTree::insert(const int &popularity, const std::string &name) {
	if (root == nullptr) {
		root = new node;

		root->keys[0] = {popularity, name};
		++root->keysCounter;
		root->isLeaf = true;

		return;
	}

	if (root->keysCounter == 2*T - 1) {
		node *newRoot = new node;
		newRoot->sons[0] = root;
		newRoot->isLeaf = false;
		splitNode(root, newRoot);
		root = newRoot;
	}

	node *tmp = root;
	int index = 0;
	while (!tmp->isLeaf) {
		for (index = 0; index < tmp->keysCounter; ++index) {
			if (popularity < tmp->keys[index].first)
				break;
		}

		if (tmp->sons[index]->keysCounter == 2*T - 1) {
			splitNode(tmp->sons[index], tmp);
			if (tmp->keys[index].first < popularity)
				++index;
		}
		tmp = tmp->sons[index];
	}

	int i;
	for (i = 0; i < tmp->keysCounter; ++i)
		if (popularity < tmp->keys[i].first)
			break;

	for (int j = tmp->keysCounter; j > i; --j)
		tmp->keys[j] = tmp->keys[j - 1];

	tmp->keys[i] = {popularity, name};
	++tmp->keysCounter;
}

void BTree::splitNode(node *toSplit, node *father) {
	node *newSon = new node;
	newSon->isLeaf = toSplit->isLeaf;
	auto value = toSplit->keys[T - 1];

	for (int i = 0; i < T - 1; ++i) {
		newSon->keys[i] = toSplit->keys[T + i];
		newSon->sons[i] = toSplit->sons[T + i];
	}
	newSon->sons[T - 1] = toSplit->sons[2*T - 1];
	toSplit->keysCounter = newSon->keysCounter = T - 1;

	/*
		* 1. for szuka pozycji dla wstawiania
		* 2. for przesuwa klucze
		* 3. for przesuwa dzieci
		*/
	int i;
	for (i = 0; i < father->keysCounter; ++i)
		if (value.first < father->keys[i].first)
			break;

	for (int j = father->keysCounter; j > i; --j)
		father->keys[j] = father->keys[j - 1];


	for (int j = father->keysCounter + 1; j > i + 1; --j)
		father->sons[j] = father->sons[j - 1];

	father->keys[i] = value;
	father->sons[i + 1] = newSon;
	++father->keysCounter;
}

std::string BTree::find(int popularity) {
    if (root == nullptr)
        return "-";
    return search(popularity, root);
}


std::string BTree::search(int &popularity, node *tmp) {
    int index;
    for (index = 0; index < tmp->keysCounter; ++index) {
        if (popularity <= tmp->keys[index].first)
            break;
    }

    if (tmp->keys[index].first == popularity && index < tmp->keysCounter)
        return tmp->keys[index].second;
    else if (tmp->isLeaf)
        return "-";
    else
        return search(popularity, tmp->sons[index]);
}


void BTree::joinNodes(node *father, int leftSonIndex) {
    node *lSon = father->sons[leftSonIndex];
    node *rSon = father->sons[leftSonIndex + 1];

    //ojciec
    lSon->keys[lSon->keysCounter] = father->keys[leftSonIndex];
    ++lSon->keysCounter;

    for (int i = leftSonIndex; i < father->keysCounter - 1; ++i)
        father->keys[i] = father->keys[i + 1];

    for (int i = leftSonIndex + 1; i < father->keysCounter; ++i)
        father->sons[i] = father->sons[i + 1];

    --father->keysCounter;

    //prawy syn ojca
    for (int i = 0; i < rSon->keysCounter; ++i) {
        lSon->keys[lSon->keysCounter] = rSon->keys[i];
        lSon->sons[lSon->keysCounter] = rSon->sons[i];
        ++lSon->keysCounter;
    }
    lSon->sons[lSon->keysCounter] = rSon->sons[rSon->keysCounter];
}

void BTree::moveKeyLtoR(node *father, int lSonIndex) {
    node *lson = father->sons[lSonIndex];
    node *rson = father->sons[lSonIndex + 1];
    auto fatherValue = father->keys[lSonIndex];

    //prawy syn
    for (int i = rson->keysCounter; i > 0; --i)
        rson->keys[i] = rson->keys[i - 1];

    rson->keys[0] = fatherValue;

    if (!rson->isLeaf) {
        for (int i = rson->keysCounter + 1; i > 0; --i) {
            rson->sons[i] = rson->sons[i - 1];
        }
        rson->sons[0] = lson->sons[lson->keysCounter];
    }// sprawdzic synow

    ++rson->keysCounter;

    //ojciec
    father->keys[lSonIndex] = lson->keys[lson->keysCounter - 1];

    //lewy syn
    --lson->keysCounter;
}

void BTree::moveKeyRtoL(node *father, int lSonIndex) {
    node *rson = father->sons[lSonIndex + 1];
    node *lson = father->sons[lSonIndex];

    //lewy syn
    lson->keys[lson->keysCounter] = father->keys[lSonIndex];
    lson->sons[lson->keysCounter + 1] = rson->sons[0];
    ++lson->keysCounter;

    //ojciec
    father->keys[lSonIndex] = rson->keys[0];

    //prawy syn
    for (int i = 0; i < rson->keysCounter - 1; ++i)
        rson->keys[i] = rson->keys[i + 1];

    if (!rson->isLeaf)
        for (int i = 0; i < rson->keysCounter; ++i)
            rson->sons[i] = rson->sons[i + 1];

    --rson->keysCounter;
}