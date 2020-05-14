# from flask import Flask, url_for, request, render_template, redirect, make_response
# app = Flask(__name__)

# @app.route("/")
# def index():
#     return redirect(url_for('hello'))

# @app.route("/hello")
# @app.route("/hello/<name>")
# def hello(name=None):
#     return render_template('hello.html', name=name)

# @app.route("/user/<username>")
# def show_user_profile(username):
#     return "User %s" % username

# @app.route("/post/<int:post_id>")
# def show_post(post_id):
#     return "Post %d" % post_id

# @app.route("/path/<path:subpath>")
# def show_subpath(subpath):
#     return "Subpath %s" % subpath

# @app.route("/projects/")
# def projects():
#     return "projects page"

# @app.route("/about")
# def about():
#     return "about page"

# @app.route("/login", methods=['GET', 'POST'])
# def login():
#     error = None
#     if request.method == 'POST':
#         return do_the_login()
#     else:
#         return show_the_login_form()

# @app.route("/user/<username>")
# def profile(username):
#     return "{}\'s profile".format(username)

# with app.test_request_context():
#     print(url_for('index'))
#     print(url_for('login'))
#     print(url_for("login",next="/"))
#     print(url_for("profile", username="asdff"))

# with app.test_request_context("/hello", method="GET"):
#     print("hellgggggg")
#     assert request.path == "/hello"
#     print("assert ok")
#     assert request.method == "GET"

# def show_the_login_form():
#     return "show login form"

# @app.errorhandler(404)
# def page_not_found(error):
#     return render_template('hello.html', name="pagenotfound"), 404
#     #resp = make_response(render_template("hello.html", name="pnf"), 404)
#     #resp.headers["X-something"] = "A value"
#     #return resp




from flask import Flask, session, redirect, url_for, escape, request

app = Flask(__name__)

# Set the secret key to some random bytes. Keep this really secret!
app.secret_key = b'_5#y2L"F4Q8z\n\xec]/'

@app.route('/')
def index():
    if 'username' in session:
        return 'Logged in as %s' % escape(session['username'])
    return 'You are not logged in'

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        session['username'] = request.form['username']
        return redirect(url_for('index'))
    return '''
        <form method="post">
            <p><input type=text name=username>
            <p><input type=submit value="asdf">
        </form>
    '''

@app.route('/logout')
def logout():
    # remove the username from the session if it's there
    session.pop('username', None)
    return redirect(url_for('index'))