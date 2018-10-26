/*
 * Assumptions:
 * Circle:
 *	ATTRIBUTES:
 *	messages - List of 10 most recent messages in this circle
 *	users	 - List of pointer to users in the circle. Sorted such that
 *		   lower index means older user.
 *
 *	MEATHODS:
 * 	push(id, string) - Add message to the front of the list and indicates the poster
 * 	pop_back()   	 - Remove oldest message
 *	kill()		 - Delete the circle
 *
 * User:
 *	ATTRIBUTES:
 *	circles - List of pointers to circles this user is in
 *
 * Message:
 *	ATTRIBUTES:
 *	id  - ID of the poster
 *	msg - Content of the post
**/

/*
 * Description: Create new post in a circle
 * Parameters:	id 	- user who is posting
 *		msg 	- contents of the post
 *		*cirlce - pointer to circle where
 *			  the post is made
 * Returns:	void
**/
void posting(id, msg, *circle) {
	circle->messages.push(id, msg);

	if (circle->messages.size() > 10) {
		circle->messages.pop_back();
	}
}

/*
 * Description:	Get messages from all of a user's circles
 * Parameters:	id - User who's messages to get
 * Returns:	List of messages
**/
vector<Message> getMessages(id) {
	vector<Message> m;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < id.circles.size(); j++) {
			m.push_back(id.circles[j]->messages[i]);
		}
	}

	return m;
}

/*
 * Description:	Add user to a circle
 * Parameters:	*id 	- pointer to user to add
 *		*circle	- pointer to circle to add to
 * Returns:	void
**/
void joinCricle(*id, *circle) {
	if (circle->users.size() < 10 || !circle->users.contains(id)) {
		circles->users.push_back(id);
		id->circles.push_back(circle);
	}
}

/*
 * Description:	Remove user from circle
 * Parameters:	*id	- pointer to user to remove
 *		*circle	- pointer to circle to remove from
 * Returns:	void
**/
void leaveCircle(*id, *circle) {
	if (circles->users[0] == id) {  // Delete circle
		circles.kill();
	}
	else {
		circles->users.erase(id);
	}

	id->circles.erase(circles);
}
