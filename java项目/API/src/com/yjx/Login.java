package com.yjx;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.json.JSONObject;

import com.yjx.ResponseJson;
import com.yjx.Sql;

import java.io.*;
import java.util.ArrayList;

/**
 * Servlet implementation class Login
 */

public class Login extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Login() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.setContentType("text/json; charset=utf-8");
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		PrintWriter out = response.getWriter();
		String msg = "µÇÂ½Ê§°Ü";
		int status = 1;
		String m = "µÇÂ½³É¹¦";
		ArrayList<JSONObject> data = new ArrayList<JSONObject>();
		JSONObject json = new JSONObject();
		json.put("username", username);
	    json.put("password", password);
	    data.add(json);
		Sql s = new Sql();
		if(s.login(username,password)) {
			status = 0;
	        msg = m;
		
		    ResponseJson res = new ResponseJson(status,msg,data);
		
		    out.println(res.json);
		}else {
			ResponseJson res = new ResponseJson(status,msg,data);
			out.println(res.json);
		}
	}


	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
