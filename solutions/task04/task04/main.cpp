#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct AVLNode {
	long key;
	short height;
	long size;
	AVLNode * right;
	AVLNode * left;
	AVLNode(long n_key) {
		left = right = NULL;
		key = n_key;
		height = 0;
		size = 1;
	}
};

long long result = 0;
AVLNode * head;

short get_height(AVLNode * p) {
	return p ? p->height : 0;
}

long get_size(AVLNode * p) {
	return p ? p->size : 0;
}

short balance_factor(AVLNode * p) {
	return get_height(p->right) - get_height(p->left);
}

void recalc_height(AVLNode * p) {
	short hleft = get_height(p->left);
	short hright = get_height(p->right);
	p->height = max(hleft, hright) + 1;
}

void recalc_size(AVLNode * p) {
	p->size = get_size(p->left) + get_size(p->right) + 1;
}

AVLNode * right_rotation(AVLNode * x) {
	AVLNode * y = x->left;
	AVLNode * T2 = y->right;
	//x->left = y->right;
	y->right = x;
	x->left = T2;
	recalc_height(x);
	recalc_height(y);
	recalc_size(x);
	recalc_size(y);
	return y;
}

AVLNode * left_rotation(AVLNode * y) {
	AVLNode * x = y->right;
	AVLNode * T2 = x->left;
	//y->right = x->left;
	x->left = y;
	y->right = T2;
	recalc_height(y);
	recalc_height(x);
	recalc_size(y);
	recalc_size(x);
	return x;
}

AVLNode * balance(AVLNode * x) {
	recalc_height(x);
	recalc_size(x);
	short bf = balance_factor(x);
	if (bf == 2) {
		if (balance_factor(x->right) < 0)
			x->right = right_rotation(x->right);
		return left_rotation(x);
	}
	if (bf == -2) {
		if (balance_factor(x->left) > 0)
			x->left = left_rotation(x->left);
		return right_rotation(x);
	}
	return x;
}

AVLNode * insert(AVLNode * x, long k) {
	if (!x)
		return new AVLNode(k);

	if (k < x->key) {
		x->left = insert(x->left, k);
		result += (long long)(get_size(x->right) + 1);
	}
	else
		x->right = insert(x->right, k);

	return balance(x);
}

//Such a pain :( was intended to be a masterpiece! 
/*
vector<long> a, tmp;

long long do_merge(long left, long mid, long right) {
	long i = left;
	long j = mid;
	long k = left;
	long long inv_count = 0;
	while ((i <= mid - 1) && (j <= right)) {
		if (a[i] <= a[j]) {
			tmp[k++] = a[i++];
		} else {
			tmp[k++] = a[j++];
			inv_count = inv_count + (mid - i);
		}
	}

	while (i <= mid - 1)
		tmp[k++] = a[i++];

	while (j <= right)
		tmp[k++] = a[j++];

	for (i=left; i <= right; i++)
		a[i] = tmp[i];

	return inv_count;
}

long long merge_sort(long left, long right) {
	long mid;
	long long inv_count;
	if (left >= right)
		return 0;

	mid = (left + right) / 2;
	inv_count = merge_sort(left, mid) + merge_sort(mid + 1, right) + do_merge(left, mid + 1, right);
	return inv_count;
}*/

int main() {
	//freopen("input.txt", "r", stdin);
	long N;
	cin >> N;
	/*a.resize(N);
	tmp.resize(N);*/
	for (long i = 0; i < N; ++i) {
		long t;
		cin >> t;
		//a[i] = t;
		head = insert(head, t);
	}
	cout << /*merge_sort(0, N - 1)*/ result << endl;
	return 0;
}