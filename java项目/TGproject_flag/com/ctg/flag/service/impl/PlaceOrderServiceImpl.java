package com.ctg.flag.service.impl;

import com.ctg.flag.dao.PlaceDao;
import com.ctg.flag.dao.PlaceOrderDao;
import com.ctg.flag.enums.PlaceOrderStateEnum;
import com.ctg.flag.pojo.dto.OptionDto;
import com.ctg.flag.pojo.dto.OrderManageDto;
import com.ctg.flag.pojo.dto.PlaceOrderDetailDto;
import com.ctg.flag.pojo.entity.Place;
import com.ctg.flag.pojo.entity.PlaceOrder;
import com.ctg.flag.service.PlaceOrderService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.util.*;

@Component
public class PlaceOrderServiceImpl implements PlaceOrderService{

    private final PlaceOrderDao placeOrderDao;

    private final PlaceDao placeDao;

    @Autowired
    public PlaceOrderServiceImpl(PlaceOrderDao placeOrderDao, PlaceDao placeDao) {
        this.placeOrderDao = placeOrderDao;
        this.placeDao = placeDao;
    }

    @Override
    public List<OptionDto<Integer, OrderManageDto>> listPlaceOfOrderByUid(Integer id) {
        // 获得该用户所有未删除的订单
        List<PlaceOrder> list = placeOrderDao.findAllByUidAndStateNot(id, PlaceOrderStateEnum.DELETED.getValue());

        // 用订单中的场地id查询场地名称
        List<OptionDto<Integer, OrderManageDto>> result = new ArrayList<>();
        for (PlaceOrder placeOrder: list) {
            String name = placeDao.findById(placeOrder.getPid()).get().getName();
            // 保留名称，用于返回；保留创建时间，用于排序
            OrderManageDto orderManageDto = new OrderManageDto(placeOrder.getCreateTime(), name);
            result.add(new OptionDto<>(placeOrder.getId(), orderManageDto));
        }
        result.sort((opt1, opt2) -> {
            OrderManageDto o1 = opt1.getOptVal();
            OrderManageDto o2 = opt2.getOptVal();

            return o1.getCreateTime().compareTo(o2.getCreateTime());
        });

        return result;
    }

    @Override
    public void save(PlaceOrder placeOrder) {
        placeOrder.setState(PlaceOrderStateEnum.PENDING.getValue());
        placeOrderDao.save(placeOrder);

        Place place = placeDao.getPlaceById(placeOrder.getPid());
        place.setCount(place.getCount()+1);
        placeDao.save(place);
    }


    /**
     *
     * 状态码小于state的预约事件
     */
    @Override
    public List<PlaceOrder> personOrderNum(int state) {
        return placeOrderDao.findAllByStateLessThan(state);
    }

    /**
     *
     * id等于id且状态码等于state的预约事件
     */
    @Override
    public List<PlaceOrder> successOrderNum(int id,int state){return placeOrderDao.findAllByPidAndState(id, state);}

    @Override
    public PlaceOrder getPlaceOrderById(Integer pid) {
        return placeOrderDao.getPlaceOrderById(pid);
    }

    public PlaceOrderDetailDto getExistedPlaceOrderById(Integer oid) {
        PlaceOrder placeOrder = placeOrderDao.getPlaceOrderByIdAndStateNot(oid, PlaceOrderStateEnum.DELETED.getValue());
        if (placeOrder == null) {
            return null;
        }
        Place place = placeDao.getPlaceById(placeOrder.getPid());

        return new PlaceOrderDetailDto(placeOrder.getId(), place.getName(), placeOrder.getState(),
                placeOrder.getStartTime(), placeOrder.getEndTime(), placeOrder.getFeedback());
    }
}
