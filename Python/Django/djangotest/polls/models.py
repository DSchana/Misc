from django.db import models

class Question(models.Model):
	text = models.CharField(max_length=200)
	date = models.DateTimeField("date published")

	def __str__(self):
		return self.text

	def isRecent(self):
		return self.date >= timezone.now() - datetime.timedelta(days=1)

class Choice(models.Model):
	question = models.ForeignKey(Question, on_delete=models.CASCADE)
	text = models.CharField(max_length=200)
	votes = models.IntegerField(default=0)

	def __str__(self):
		return self.text
