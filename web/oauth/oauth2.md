# OAuth

## 应用场景

1. 第三方服务保存用户的密码不是很安全。
2. 第三方服务需要提供用户登陆功能，输入秘密登陆不是很安全。
3. 第三方服务获得用户密码，也就获得所有的资料和权力，无法对用户的权限范围和有效期做限制。
4. 用户只有修改代码，才能收回赋予第三方服务的权力，但是也会导致其他第三方软件的权力。
5. 如果第三方应用程序被破解，容易泄漏用户秘密。

## 关键词

1. third party application 第三方服务
2. http service            auth服务提供商
3. resource owner          用户
4. user agent              用户代理
5. authorization server    认证服务器
6. resource server         资源服务器

### OAuth思路

OAuth在客户端与服务提供商之间，设置一个授权层(authorization layer)。客户端不能直接登陆服务提供商，只能登陆授权层，以此将用户与客户端区分开。客户端登陆授权层所用的令牌(token)，指定授权层令牌的权限范围和有效期。

### OAuth流程

![OAuth2 flow](https://raw.githubusercontent.com/ErlichChen/example-asset/master/oauth2-flow.png)

1. 用户打开客户端以后，客户端要求用户给予授权。
2. 用户同意给予客户端授权。
3. 客户端使用上一步获得的授权，向认证服务器申请令牌。
4. 认证服务器对客户进行认证后，确认无误，同意发放令牌。
5. 客户端使用令牌，向资源服务器申请获取资源。
6. 资源服务器确认令牌无误，同意向客户端开放资源。

### 客户端的授权模式

* 授权码模式(authorization code)
* 简化模式(implicit)
* 密码模式(resource owner password credentials)
* 客户端模式(client credentials)

### 授权码模式

![OAuth2 Authorization Code flow](https://raw.githubusercontent.com/ErlichChen/example-asset/master/oauth2-authorization-code.png)

授权码模式(authorization code)是功能最完整、流程最严密的授权模式。它通过客户端的后台服务器，与服务提供商的认证服务器进行认证。

1. 用户访问客户端，客户端后台服务器重定向认证服务器。

```s
GET /authorize?response_type=code&client_id=s6BhdRkqt3&state=xyz&redirect_uri=https%3A%2F%2Fclient%2Eexample%2Ecom%2Fcb HTTP/1.1
Host: server.example.com
```

* response_type：表示授权类型，必选项，此处的值固定为"code"
* client_id：表示客户端的ID，必选项
* redirect_uri：表示重定向URI，可选项
* scope：表示申请的权限范围，可选项
* state：表示客户端的当前状态，可以指定任意值，认证服务器会原封不动地返回这个值。

2. 用户选择是否给予客户端授权。

3. 假设用户给予授权，认证服务器将用户定向客户端事先指定的"重定向URI"，同时附上一个授权码。

```s
HTTP/1.1 302 Found
Location: https://client.example.com/cb?code=SplxlOBeZQQYbYS6WxSbIA&state=xyz
```

* code: 表示授权码，必选项。该码的有效期应该很短，通常设为10分钟，客户端只能使用该码一次，否则会被授权服务器拒绝。该码与客户端ID和重定向URI，是一一对应关系。
* state: 如果客户端的请求中包含这个参数，认证服务器的回应也必须相同包含这个参数。

4. 客户端收到授权码，附上预先的"重定向URI"，向认证服务器申请令牌。这一步是在客户端后台服务器上完成，对用户不可见。

```s
POST /token HTTP/1.1
Host: server.example.com
Authorization: Basic czZCaGRSa3F0MzpnWDFmQmF0M2JW
Content-Type: application/x-www-form-urlencoded
grant_type=authorization_code&code=SplxlOBeZQQYbYS6WxSbIA&redirect_uri=https%3A%2F%2Fclient%2Eexample%2Ecom%2Fcb
```

* grant_type：表示使用的授权模式，必选项，此处的值固定为"authorization_code"。
* code：表示上一步获得的授权码，必选项。
* redirect_uri：表示重定向URI，必选项，且必须与A步骤中的该参数值保持一致。
* client_id：表示客户端ID，必选项。

5. 认证服务器核对了授权码和重定向URI，确定无误后，向客户端发送访问令牌(access token)和更新令牌(refresh token)。

```s
HTTP/1.1 200 OK
Content-Type: application/json;charset=UTF-8
Cache-Control: no-store
Pragma: no-cache

{
	"access_token":"2YotnFZFEjr1zCsicMWpAA",
	"token_type":"example",
	"expires_in":3600,
	"refresh_token":"tGzv3JOkF0XG5Qx2TlKWIA",
	"example_parameter":"example_value"
}
```

### 简化模式

![OAuth2 implict](https://raw.githubusercontent.com/ErlichChen/example-asset/master/oauth2-implict.png)

简化模式(implicit grant type)不通过第三方应用程序的服务器，直接在浏览器中向认证服务器申请令牌，跳过了授权码这个步骤。所有步骤在浏览器中完成，令牌对访问者是可见的，且客户端不需要认证。

1. 客户端将用户导向认证服务器。

```s
GET /authorize?response_type=token&client_id=s6BhdRkqt3&state=xyz&redirect_uri=https%3A%2F%2Fclient%2Eexample%2Ecom%2Fcb HTTP/1.1
    Host: server.example.com
```

* response_type: 表示授权类型，此处的值固定为"token"，必选项。
* client_id: 表示客户端的ID，必选项。
* redirect_uri: 表示重定向的URI，可选项。
* scope: 表示权限范围，可选项。
* state: 表示客户端的当前状态，可以指定任意值，认证服务器会原封不动地返回这个值。

2. 用户决定是否给于客户端授权。

3. 假设用户给予授权，认证服务器将用户导向客户端指定的"重定向URI"，并在URI的Hash部分包含了访问令牌。

```s
HTTP/1.1 302 Found
		Location: http://example.com/cb#access_token=2YotnFZFEjr1zCsicMWpAA&state=xyz&token_type=example&expires_in=3600
```

* access_token：表示访问令牌，必选项。
* token_type：表示令牌类型，该值大小写不敏感，必选项。
* expires_in：表示过期时间，单位为秒。如果省略该参数，必须其他方式设置过期时间。
* scope：表示权限范围，如果与客户端申请的范围一致，此项可省略。
* state：如果客户端的请求中包含这个参数，认证服务器的回应也必须一模一样包含这个参数。

4. 浏览器向资源服务器发出请求，其中不包括上一步收到的Hash值。

5. 资源服务器返回一个网页，其中包含的代码可以获取Hash值中的令牌。

6. 浏览器执行上一步获得的脚本，提取出令牌。

7. 浏览器将令牌发给客户端。

### 密码模式

![OAuth2 password](https://raw.githubusercontent.com/ErlichChen/example-asset/master/oauth2-password.png)

密码模式(Resource Owner Password Credentials Grant)中，用户向客户端提供自己的用户名和密码。客户端使用这些信息，向"服务商提供商"索要授权。
在这种模式中，用户必须把自己的密码给客户端，但是客户端不得储存密码。这通常用在用户对客户端高度信任的情况下，比如客户端是操作系统的一部分，或者由一个著名公司出品。而认证服务器只有在其他授权模式无法执行的情况下，才能考虑使用这种模式。

1. 用户向客户端提供用户名和密码。

2. 客户端将用户名和密码发给认证服务器，向后者请求令牌。

```s
POST /token HTTP/1.1
Host: server.example.com
Authorization: Basic czZCaGRSa3F0MzpnWDFmQmF0M2JW
Content-Type: application/x-www-form-urlencoded
grant_type=password&username=johndoe&password=A3ddj3w
```

* grant_type: 表示授权类型，此处的值固定为"password"，必选项。
* username: 表示用户名，必选项。
* password: 表示用户的密码，必选项。
* scope: 表示权限范围，可选项

3. 认证服务器确认无误后，向客户端提供访问令牌。

```s
HTTP/1.1 200 OK
Content-Type: application/json;charset=UTF-8
Cache-Control: no-store
Pragma: no-cache
{
	"access_token":"2YotnFZFEjr1zCsicMWpAA",
	"token_type":"example",
	"expires_in":3600,
	"refresh_token":"tGzv3JOkF0XG5Qx2TlKWIA",
	"example_parameter":"example_value"
}
```

### 客户端模式

![OAuth2 Client](https://raw.githubusercontent.com/ErlichChen/example-asset/master/oauth2-client.png)

客户端模式(Client Credentials Grant)指客户端以自己的名义，而不是以用户的名义，向服务提供商进行认证。严格地说，客户端模式并不属于OAuth框架所要解决的问题。在这种模式中，用户直接向客户端注册，客户端以自己的名义要求服务提供商提供服务，其实不存在授权问题。

1. 客户端向认证服务器进行身份认证，并要求一个访问令牌。

```s
POST /token HTTP/1.1
Host: server.example.com
Authorization: Basic czZCaGRSa3F0MzpnWDFmQmF0M2JW
Content-Type: application/x-www-form-urlencoded
grant_type=client_credentials
```
* granttype：表示授权类型，此处的值固定为"clientcredentials"，必选项。
* scope：表示权限范围，可选项

2. 认证服务器确认之后，向客户端提供访问令牌。

```s
HTTP/1.1 200 OK
Content-Type: application/json;charset=UTF-8
Cache-Control: no-store
Pragma: no-cache
{
	"access_token":"2YotnFZFEjr1zCsicMWpAA",
	"token_type":"example",
	"expires_in":3600,
	"example_parameter":"example_value"
}
```

### 更新令牌

如何客户端的访问令牌已经过期，则需要使用更新令牌申请一个新的访问令牌。

客户端发出更新令牌的HTTP请求，包含以下参数：

* granttype：表示使用的授权模式，此处的值固定为"refreshtoken"，必选项。
* refresh_token：表示早前收到的更新令牌，必选项。
* scope：表示申请的授权范围，不可以超出上一次申请的范围，如果省略该参数，则表示与上一次一致。

```s
POST /token HTTP/1.1
Host: server.example.com
Authorization: Basic czZCaGRSa3F0MzpnWDFmQmF0M2JW
Content-Type: application/x-www-form-urlencoded
grant_type=refresh_token&refresh_token=tGzv3JOkF0XG5Qx2TlKWIA
```



