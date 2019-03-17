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
 * Servlet implementation class AttainArticles
 */

public class AttainArticles extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AttainArticles() {
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
		
		String msg = "获取失败";
		int status = 1;
		String m = "获取成功";
		
		ArrayList<JSONObject> data = new ArrayList<JSONObject>();
		JSONObject json = new JSONObject();
		Sql s = new Sql();
		StringBuffer text = new StringBuffer("");
		
		if(s.attainArticle(title,text)) {
		status = 0;
	    msg = m;
		json.put("title",title);
		json.put("article", text);
		
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
