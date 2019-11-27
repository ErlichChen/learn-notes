# Implementing OAuth 2.0 with node

OAuth2 is an authentication protocol that is used to authenticate and authorize users in an application by using anothor service provider.

## OAuth2 flow

![OAuth2 github](https://raw.githubusercontent.com/ErlichChen/example-asset/master/oauth2-github.png)

When we are trying to login to Gitlab using Github to authenticate. There are three parties in any OAuth flow:

* The client - The person, or user who is logging in.
* The consumer - The application that the client wants to log in to.
* The service provider - The external application through which the user authenticates.

https://github.com/login/oauth/authorize?client_id=myclientid123&redirect_uri=http://localhost:8080/oauth/redirect

1.Register your new application on Github : https://github.com/settings/applications/new. In the "callback URL" field, enter "http://localhost:8080/oauth/redirect". Once you register, you will get a client ID and client secret.

2. Replace the values of the clientID and clientSecret variables in the index.js file

3. Install dependencies by executing: npm install or yarn.

4. Start the server by executing node index.js

5. Navigate to http://localhost:8080 on your browser.
