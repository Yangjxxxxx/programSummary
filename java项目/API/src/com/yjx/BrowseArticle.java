package com.yjx;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.yjx.ResponseJson;
import com.yjx.Sql;
import org.json.JSONObject;

/**
 * Servlet implementation class BrowseArticle
 */

public class BrowseArticle extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public BrowseArticle() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		response.setContentType("text/json; charset=utf-8");
		
		PrintWriter out = response.getWriter();
		
		String msg = "获取文章失败";
		int status = 1;
		String m = "获取文章成功";
		
		Sql s = new Sql();
		ArrayList<JSONObject> articleList = new ArrayList<JSONObject>();
		
		if(s.browseArticle(articleList)) {
			status = 0;
	        msg = m;
	        
		
		    ResponseJson res = new ResponseJson(status,msg,articleList);
		
		    out.println(res.json);
		}else {
			ResponseJson res = new ResponseJson(status,msg,articleList);
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
