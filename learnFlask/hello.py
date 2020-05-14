from flask import Flask, url_for, request, render_template
app = Flask(__name__)

@app.route("/")
def index():
    return "Index Page"

@app.route("/hello")
@app.route("/hello/<name>")
def hello(name=None):
    return render_template('hello.html', name=name)

@app.route("/user/<username>")
def show_user_profile(username):
    return "User %s" % username

@app.route("/post/<int:post_id>")
def show_post(post_id):
    return "Post %d" % post_id

@app.route("/path/<path:subpath>")
def show_subpath(subpath):
    return "Subpath %s" % subpath

@app.route("/projects/")
def projects():
    return "projects page"

@app.route("/about")
def about():
    return "about page"

@app.route("/login", methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        return do_the_login()
    else:
        return show_the_login_form()

@app.route("/user/<username>")
def profile(username):
    return "{}\'s profile".format(username)

with app.test_request_context():
    print(url_for('index'))
    print(url_for('login'))
    print(url_for("login",next="/"))
    print(url_for("profile", username="asdff"))

def show_the_login_form():
    return "show login form"


