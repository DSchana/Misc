#include <cstdio>
#include <string>
#include <vector>

using namespace std;

struct Post {
	int likes;
	int comments;
	int size;
	int date;
	string name;
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
			showPosts(posts);
			break;
		case 2:
			// Show post by
			showPosts(posts, true);
			break;
		case 3:
			// Show number of posts
			printf("There are %d posts currently stored\n", posts.size());
			break;
		case 4:
			// Add new post
			editPostList(*posts, true);
			break;
		case 5:
			// Delete post by
			editPostList(*posts, false);
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
			sort(*posts, userIn);

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
		// ask for condition
	}
	else {
		// Print all data
	}
}

void editPostList(vector<Post> *posts, bool addition) {
	if (addition) {
		// New post
	}
	else {
		// delete post
	}
}

void sort(vector<Post> *posts, int condition) {
	// Try radix sort??
}
