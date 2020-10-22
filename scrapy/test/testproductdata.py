import json
data= '''
{"status":200,"appVersion":"3.2.0","serverTime":"2020-10-22 22:58:15","data":{"product":{"product_id":5102938,"sku_code":"6081370005049","name":"\u30b8\u30e7\u30fc\u30c0\u30f3\u30ba\u30fc\u30e0\u201992","site_type":1,"brand_id":0,"brand_name":"NIKE","image":["https:\/\/img.apim.abc-mart.biz\/img\/6081\/6081370005\/608137000501.jpg","https:\/\/img.apim.abc-mart.biz\/img\/6081\/6081370005\/608137000502.jpg","https:\/\/img.apim.abc-mart.biz\/img\/6081\/6081370005\/608137000503.jpg","https:\/\/img.apim.abc-mart.biz\/img\/6081\/6081370005\/608137000504.jpg","https:\/\/img.apim.abc-mart.biz\/img\/6081\/6081370005\/608137000505.jpg","https:\/\/img.apim.abc-mart.biz\/img\/6081\/6081370005\/608137000506.jpg","https:\/\/img.apim.abc-mart.biz\/img\/6081\/6081370005\/608137000507.jpg","https:\/\/img.apim.abc-mart.biz\/img\/6081\/6081370005\/608137000508.jpg"],"color":"004BLK\/GAMERL","price":18150,"sale_price":null,"price_view_type":1,"new_flag":true,"favorite_flag":false,"shop_receipt_flag":true,"size":[{"sku_code":"6081370005050","product_item_id":5102939,"name":"25.5cm","stock":0,"shipping_day":"2020\/10\/23","restock_flag":false,"stock_status":3,"coming_soon_flg":true},{"sku_code":"6081370005049","product_item_id":5102938,"name":"25cm","stock":0,"shipping_day":"2020\/10\/23","restock_flag":false,"stock_status":3,"coming_soon_flg":true},{"sku_code":"6081370005052","product_item_id":5102941,"name":"26.5cm","stock":0,"shipping_day":"2020\/10\/23","restock_flag":false,"stock_status":3,"coming_soon_flg":true},{"sku_code":"6081370005051","product_item_id":5102940,"name":"26cm","stock":0,"shipping_day":"2020\/10\/23","restock_flag":false,"stock_status":3,"coming_soon_flg":true},{"sku_code":"6081370005054","product_item_id":5102943,"name":"27.5cm","stock":0,"shipping_day":"2020\/10\/23","restock_flag":false,"stock_status":3,"coming_soon_flg":true},{"sku_code":"6081370005053","product_item_id":5102942,"name":"27cm","stock":0,"shipping_day":"2020\/10\/23","restock_flag":false,"stock_status":3,"coming_soon_flg":true},{"sku_code":"6081370005056","product_item_id":5102945,"name":"28.5cm","stock":0,"shipping_day":"2020\/10\/23","restock_flag":false,"stock_status":3,"coming_soon_flg":true},{"sku_code":"6081370005055","product_item_id":5102944,"name":"28cm","stock":0,"shipping_day":"2020\/10\/23","restock_flag":false,"stock_status":3,"coming_soon_flg":true},{"sku_code":"6081370005057","product_item_id":5102946,"name":"29cm","stock":0,"shipping_day":"2020\/10\/23","restock_flag":false,"stock_status":3,"coming_soon_flg":true},{"sku_code":"6081370005059","product_item_id":5102948,"name":"30cm","stock":0,"shipping_day":"2020\/10\/23","restock_flag":false,"stock_status":3,"coming_soon_flg":true},{"sku_code":"6081370005060","product_item_id":5102949,"name":"31cm","stock":0,"shipping_day":"2020\/10\/23","restock_flag":false,"stock_status":3,"coming_soon_flg":true},{"sku_code":"6081370005061","product_item_id":5102950,"name":"32cm","stock":0,"shipping_day":"2020\/10\/23","restock_flag":false,"stock_status":3,"coming_soon_flg":true}],"shareText":"\u30b8\u30e7\u30fc\u30c0\u30f3\u30ba\u30fc\u30e0\u201992 | ABC-MART \u3010\u516c\u5f0f\u901a\u8ca9\u3011  https:\/\/www.abc-mart.net\/shop\/g\/g6081370005049\/","description":"90\u5e74\u4ee3\u306e\u30d0\u30b9\u30b1\u30c3\u30c8\u30dc\u30fc\u30eb\u30b7\u30e5\u30fc\u30ba\u306b\u656c\u610f\u3092\u8868\u3057\u305f\u4e00\u8db3\u3002\u5c65\u304d\u5fc3\u5730\u3092\u91cd\u8996\u3057\u3064\u3064\u3001\u5f53\u6642\u306e\u5927\u80c6\u306a\u30c7\u30b6\u30a4\u30f3\u3092\u518d\u73fe\u3002\u4f38\u7e2e\u6027\u306e\u3042\u308b\u30b9\u30ea\u30fc\u30d6\u3068\u8db3\u88cf\u306e\u30af\u30c3\u30b7\u30e7\u30f3\u304c\u5feb\u9069\u306a\u30d5\u30a3\u30c3\u30c8\u611f\u3092\u5b9f\u73fe\u300290\u5e74\u4ee3\u3092\u30a4\u30e1\u30fc\u30b8\u3057\u305f\u30c7\u30a3\u30c6\u30fc\u30eb\u304c\u30ec\u30c8\u30ed\u306a\u30b9\u30bf\u30a4\u30eb\u3092\u6f14\u51fa\u3002\u3010\u30b5\u30a4\u30ba\u76ee\u5b89\u3011<br>(\u500b\u4eba\u5dee\u304c\u3054\u3056\u3044\u307e\u3059\u306e\u3067\u3001\u3042\u304f\u307e\u3067\u3082\u76ee\u5b89\u3068\u304a\u8003\u3048\u4e0b\u3055\u3044\u3002)<br><br>\u3053\u306e\u30b7\u30e5\u30fc\u30ba\u306e\u4f5c\u308a\u306f\u5c0f\u3055\u3081\u3067\u3059\u3002<br><br>","product_code":"6081370005","material":"\u5408\u6210\u6a39\u8102 \u30fb\u5408\u6210\u7e4a\u7dad","category":"\u30ed\u30fc\u30ab\u30c3\u30c8\u30b9\u30cb\u30fc\u30ab\u30fc"}},"errorType":0}'''

obj=json.loads(data.encode('utf-8'))
productData={}
for p in obj['data']['product']['size']:
    productData[p['sku_code']]=p['name']