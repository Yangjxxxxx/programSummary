package com.yjx;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.json.JSONObject;

/**
 * Servlet implementation class DeleteArticles
 */

public class DeleteArticles extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DeleteArticles() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.setContentType("text/json; charset=utf-8");
		String title = request.getParameter("title");
		PrintWriter out = response.getWriter();
		
		String msg = "É¾³ýÊ§°Ü";
		int status = 1;
		String m = "É¾³ý³É¹¦";
		
		ArrayList<JSONObject> data = new ArrayList<JSONObject>();
		JSONObject json = new JSONObject();
		Sql s = new Sql();
		
		if(s.deleteArticle(title)) {
		status = 0;
	    msg = m;
		json.put("title",title);
		
		data.add(json);
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
