#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Post {
	int likes;
	int comments;
	int size;
	int date;
	char name[100];
};

void showPosts(vector<Post> posts, bool conditional);
void editPostList(vector<Post> *posts, bool addition);
void sort(vector<Post> *posts, int condition);

int main() {
	vector<Post> posts;
	int userIn;

	while (true) {
		printf("1. Show posts\n");
		printf("2. Show post by\n");
		printf("3. Show number of posts\n");
		printf("4. Add new post\n");
		printf("5. Delete post by\n");
		printf("6. Delete all posts\n");
		printf("7. Sort posts by\n");
		printf("8. Exit\n");
		printf("Choose one of the above by number: ");
		scanf("%d", &userIn);

		switch(userIn) {
		case 1:
			// Show posts
			showPosts(posts, false);
			break;
		case 2:
			// Show post by
			showPosts(posts, true);
			break;
		case 3:
			// Show number of posts
			printf("There are %d posts currently stored\n", (int)posts.size());
			break;
		case 4:
			// Add new post
			editPostList(&posts, true);
			break;
		case 5:
			// Delete post by
			editPostList(&posts, false);
			break;
		case 6:
			posts.clear();
			break;
		case 7:
			// Sort posts by
			printf("1. Number of likes\n");
			printf("2. Number of comments\n");
			printf("3. Date posted\n");
			printf("4. Post size\n");
			printf("Choose one of the above as a sorting condition: ");
			scanf("%d", &userIn);
			sort(&posts, userIn);

			break;
		case 8:
			return 0;
		default:
			printf("Invalid Option\n");
			break;
		}
	}

	return 0;
}

void showPosts(vector<Post> posts, bool conditional = false) {
	if (conditional) {
		int userIn, target;
		char s_target[100];

		printf("1. Number of likes\n");
		printf("2. Number of comments\n");
		printf("3. Date posted\n");
		printf("4. Post size\n");
		printf("5. Name\n");
		printf("Choose one of the above as a sorting condition: ");
		scanf("%d", &userIn);

		switch (userIn) {
		case 1:
			printf("Enter the number of likes: ");
			scanf("%d", &target);
			for (int i = 0; i < posts.size(); i++) {
				if (posts[i].likes == target) {
					printf("%s posted a %d character post on %d. It received %d likes and %d comments.\n", posts[i].name, posts[i].size, posts[i].date, posts[i].likes, posts[i].comments);
					break;
				}
			}
			printf("No records found.\n");

			break;
		case 2:
			printf("Enter the number of comments: ");
			scanf("%d", &target);
			for (int i = 0; i < posts.size(); i++) {
				if (posts[i].comments == target) {
					printf("%s posted a %d character post on %d. It received %d likes and %d comments.\n", posts[i].name, posts[i].size, posts[i].date, posts[i].likes, posts[i].comments);
					break;
				}
			}
			printf("No records found.\n");

			break;
		case 3:
			printf("Enter the post date: ");
			scanf("%d", &target);
			for (int i = 0; i < posts.size(); i++) {
				if (posts[i].date == target) {
					printf("%s posted a %d character post on %d. It received %d likes and %d comments.\n", posts[i].name, posts[i].size, posts[i].date, posts[i].likes, posts[i].comments);
					break;
				}
			}
			printf("No records found.\n");

			break;
		case 4:
			printf("Enter the size of the post: ");
			scanf("%d", &target);
			for (int i = 0; i < posts.size(); i++) {
				if (posts[i].size == target) {
					printf("%s posted a %d character post on %d. It received %d likes and %d comments.\n", posts[i].name, posts[i].size, posts[i].date, posts[i].likes, posts[i].comments);
					break;
				}
			}
			printf("No records found.\n");

			break;
		case 5:
			printf("Enter the name: ");
			scanf("%s", s_target);
			for (int i = 0; i < posts.size(); i++) {
				if (posts[i].name == s_target) {
					printf("%s posted a %d character post on %d. It received %d likes and %d comments.\n", posts[i].name, posts[i].size, posts[i].date, posts[i].likes, posts[i].comments);
					break;
				}
			}
			printf("No records found.\n");

			break;
		default:
			printf("Invalid Option\n");
			break;
		}
	}
	else {
		for (int i = 0; i < posts.size(); i++) {
			printf("%s posted a %d character post on %d. It received %d likes and %d comments.\n", posts[i].name, posts[i].size, posts[i].date, posts[i].likes, posts[i].comments);
		}
	}
}

void editPostList(vector<Post> *posts, bool addition) {
	if (addition) {
		Post n_post;

		printf("Enter name: ");
		scanf("%s", n_post.name);

		printf("Enter likes: ");
		scanf("%d", &n_post.likes);

		printf("Enter comments: ");
		scanf("%d", &n_post.comments);

		printf("Enter size of post in number of characters: ");
		scanf("%d", &n_post.size);

		printf("Enter date of post in the form YYYYMMDD: ");
		scanf("%d", &n_post.date);

		(*posts).push_back(n_post);
	}
	else {
		int target, userIn;
		char s_target[100];

		printf("Delete by 1. author or 2. date: ");
		scanf("%d", &userIn);

		if (userIn == 1) {
			printf("Enter name: ");
			scanf("%s", s_target);

			for (int i = 0; i < (*posts).size(); i++) {
				if ((*posts)[i].name == s_target) {
					(*posts).erase((*posts).begin() + i);
				}
			}
		}
		else if (userIn == 2) {
			printf("Enter date in the form of YYYYMMDD: ");
			scanf("%d", &target);

			for (int i = 0; i < (*posts).size(); i++) {
				if ((*posts)[i].date == target) {
					(*posts).erase((*posts).begin() + i);
				}
			}
		}
		else {
			printf("Invalid Option\n");
		}
	}
}

void sort(vector<Post> *posts, int condition) {
	bool swapped = true;

	switch (condition) {
	case 1:
		// Likes
		while (swapped) {
			swapped = false;

			for (int i = 0; i < (*posts).size() - 1; i++) {
				if ((int)(*posts)[i].likes > (int)(*posts)[i + 1].likes) {
					iter_swap(posts->begin() + i, posts->begin() + i + 1);
					swapped = true;
				}
			}
		}

		break;
	case 2:
		// Comments
		while (swapped) {
 			swapped = false;

			for (int i = 0; i < (*posts).size() - 1; i++) {
				if ((*posts)[i].comments > (*posts)[i + 1].comments) {
					iter_swap(posts->begin() + i, posts->begin() + i + 1);
					swapped = true;
				}
			}
		}

		break;
	case 3:
		// Date
		while (swapped) {
			swapped = false;

			for (int i = 0; i < (*posts).size() - 1; i++) {
				if ((*posts)[i].date > (*posts)[i + 1].date) {
					iter_swap(posts->begin() + i, posts->begin() + i + 1);
					swapped = true;
				}
			}
		}

		break;
	case 4:
		// Size
		while (swapped) {
			swapped = false;

			for (int i = 0; i < (*posts).size() - 1; i++) {
				if ((*posts)[i].size > (*posts)[i + 1].size) {
					iter_swap(posts->begin() + i, posts->begin() + i + 1);
					swapped = true;
				}
			}
		}

		break;
	default:
		break;
	}
}
