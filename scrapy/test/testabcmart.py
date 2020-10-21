
from bs4 import BeautifulSoup
text = '''
<!DOCTYPE html>
<html lang="ja">
<head>

<meta http-equiv="Content-Type" content="text/html; charset=Shift_JIS">

<title>ご注文方法の指定 | ABC-MART 【公式通販】 </title>
<meta name="description" content="【ABC-MART公式通販】をお探しならこちらのページをどうぞ。ABC-MARTは幅広い品揃えで、お買い得なセール商品も多数取り揃えています。税込5,000円以上なら送料無料！">
<meta name="keywords" content="靴,シューズ,スニーカー,通販,通信販売,ABCマート, ABC MART,エービーシーマート,あｂｃ">

  
    <meta http-equiv="Content-Type" content="text/html; charset=Shift_JIS">
<meta http-equiv="content-style-type" content="text/css">
    <link rel="stylesheet" type="text/css" href="/new_css/reset.css" media="all">
    <link rel="stylesheet" type="text/css" href="/new_css/layout/s_lmr.css" media="all">
    <link rel="stylesheet" type="text/css" href="/new_css/common.css" media="all">
    <link rel="stylesheet" type="text/css" href="/new_css/sidebox.css" media="all">
    <link rel="stylesheet" type="text/css" href="/new_css/category.css" media="all">
    <link rel="stylesheet" type="text/css" href="/new_css/goods.css" media="all">
    <link rel="stylesheet" type="text/css" href="/new_css/order.css" media="all">
    <link rel="stylesheet" type="text/css" href="/new_css/customer.css" media="all">
    <link rel="stylesheet" type="text/css" href="/new_css/etc.css" media="all">
    <link rel="stylesheet" type="text/css" href="/new_css/quickorder.css" media="all">
    <link rel="stylesheet" type="text/css" href="/new_css/userreview.css" media="all">
    <link rel="stylesheet" type="text/css" href="/new_css/core.css" media="all">
    <link rel="stylesheet" type="text/css" href="/new_css/skin.css" media="all">
    <link rel="stylesheet" type="text/css" href="/new_css/dropframe.css" media="all">
    <link rel="stylesheet" type="text/css" href="/new_css/freepage.css" media="all">
    <link rel="stylesheet" type="text/css" href="/new_css/slick-theme.css">
    <link rel="stylesheet" type="text/css" href="/new_css/slick.css">
    <link rel="stylesheet" type="text/css" href="/new_css/user.css" media="all">
    <link rel="stylesheet" type="text/css" href="/new_css/ui-lightness/jquery-ui.css" media="all">
<meta http-equiv="content-script-type" content="text/javascript">
    <script language="JavaScript" type="text/javascript" src="/new_js/jquery-3.4.1.min.js"></script>
    <script language="JavaScript" type="text/javascript" src="/new_js/jquery-migrate-1.4.1.min.js"></script>
    <script language="JavaScript" type="text/javascript" src="/new_js/jquery-migrate-3.1.0.min.js"></script>
    <script src="/new_js/lazyload.min.js"></script>
    <script language="JavaScript" type="text/javascript" src="/new_js/slick.min.js"></script>
    <script language="JavaScript" type="text/javascript" src="/new_js/common.js"></script>
    <script src="/new_js/user.js"></script>
    <script language="JavaScript" type="text/javascript" src="/js/jquery-ui.js"></script>
    <script language="JavaScript" type="text/javascript" src="/new_js/lookupzip.js"></script> 
    <link rel="alternate" type="application/rss+xml" title="ecbeing topic feed" href="/topic/feed.rss">
    <link rel="SHORTCUT ICON" href="/favicon.ico">
    <link href="https://fonts.googleapis.com/css?family=Montserrat:600,700&amp;display=swap" rel="stylesheet">




  



<link rel="stylesheet" type="text/css" href="/css/core.css" />
<link rel="stylesheet" type="text/css" href="/css/skin.css" />
</head>
<body >










  

    

    

    
      
    
  
  <!-- Rendering BodyContents Start -->

<script src="/new_js/order_method_point.js" type="text/javascript"></script>

<div class="container_">
<!-- contents_-->
<div class="contents_">

<nav class="temp-path">
<ul>

  <li><a href="/shop/?sgender=d">トップ</a></li>

  <li>
    <p>></p>
  </li>
  <li>
    <p>ご注文方法の指定</p>
  </li>
</ul>
</nav>

<section class="cart">
<h1 class="heading_ttl-lv1">ご注文方法の指定</h1>

<div class="cartlist_">
  <div class="order_flow_"><img src="/new_img/sys/order_step2.png" alt="STEP2 ご注文方法の指定"></div>

<form method="post" action="/shop/order/method.aspx" name="frm">
<input type="image" value="submit" src="/new_img/sys/spacer.gif" name="submit" alt="次へ" class="hiddenEnter_" tabindex="1" >

<div class="method_host_">
  <h2 class="common_headline2_">ご注文者</h2>
  <div class="host_info_">
    <p class="host_name_"><strong>ｙｏｕ ｚｉ 様</strong></p>
    <address class="ads">
    〒 828-8768<br>
    北海道ｆａｗｅｇｂａｒｅｆａｗｅｇｒｅａｇ<br>
    
    
    TEL: 04-9769-5645
    </address>
    
  </div>
</div>
 
<input type="hidden" name="mode" value="">


<script language="JavaScript">
    function sendDest(dest)
    {
      //document.form1.dest.value=dest;
      document.form1.dest.name='changedest'+dest+'.x';
      document.form1.submit();
    }
    </script>
    <input type="hidden" id="dest" name="" value="">
    
<div class="method_address_" id="address1">
  <div class="address_bottom_">
    <h2 class="common_headline2_">お届け先</h2>


    <input class="button_" type="image" name="otherdest" src="/new_img/sys/button/addr.png" alt="新しいお届け先を登録する">

  </div>
  <div class="addresslist_">
<div class="address_item_">
  <div class="address_title_">
    <input class="input_none" type="radio" name="dest1" value="0" id="dest1_r0" checked  onclick="select_UseDest('0');">
    <label class="address_label" for="dest1_r0">
        <strong class="address_name">ｙｏｕ　ｚｉ 様<br></strong>
        <address class="address_area">
          〒 828-8768<br>
          北海道ｆａｗｅｇｂａｒｅｆａｗｅｇｒｅａｇ　<br>
          ｙｏｕ ｚｉ 様<br>
          TEL：04-9769-5645
        </address>
    </label>
  </div>

</div>
  </div>
  <input type="hidden" name="dest_no" value="0">
</div>
<script type="text/javascript">
  function select_UseDest(dest_){
    jQuery('input[name="dest_no"]').val(dest_);
  }
</script>


<div class="method_point_" id="method_point">
  <h2 class="common_headline2_">ポイント利用</h2>
  
  <p class="point_label">現在ポイントはありません。</p>
  
  
</div>
<script type="text/javascript">
jQuery(document).ready(function(){
click_UsePointRadio();
});
</script>



<div class="method_coupon_" id="method_coupon">
  <h2 class="common_headline2_">クーポンコードを入力する</h2>
  <p class="coupon_text">1回のご注文(ご決済)時にクーポン対象商品を複数点ご購入の際もご使用頂けるクーポンは1回のみとなります。</p>

  <h3>
  
  
  
  </h3>
  <ul class="couponList_">
    <li class="coupon_item_">
      <label class="point_label" for="coupon1_r0">クーポンコードを入力する
      
      <input class="point_text" id="coupon1_r0_num" type="text" name="coupon" value="" >
      
      </label>
      
      
      
    </li>
  </ul>
  <ul class="couponcardList_">
  
  </ul>
</div>


<script type="text/javascript">
  function select_UseCoupon(coupon_){
    jQuery('input[name="coupon"]').val(coupon_);
  }
</script>

<div class="method_box_" id="method_pay">
  <h2 class="common_headline2_">お支払い方法</h2>

  <div class="method_box_content_ payment_frame_ bottom">
<input class="point_input" type="radio" id="method_rH" name="method" value="H" >
<label class="point_label" for="method_rH">ｄ払い(ドコモ)</label>
<input class="point_input" type="radio" id="method_r7" name="method" value="7" >
<label class="point_label" for="method_r7">クレジットカード</label>
<input class="point_input" type="radio" id="method_r2" name="method" value="2" >
<label class="point_label" for="method_r2">代金引換</label>
<input class="point_input" type="radio" id="method_rD" name="method" value="D" >
<label class="point_label" for="method_rD">後払い</label>

  </div>




  <p class="gift_card">
    <input class="check_input" id="gift_check" type="checkbox" name="method" value="G" >
    <label class="check_label" for="gift_check">ギフトカード<span class="gift_caution_text">※ギフトカードは「ABC-MART GIFT CARD」のみご利用可能となります。</span></label>
  </p>


<div class="credit_area js-gift_card"  id="method_gift">
  <dl class="credit_list_">
    <dt class="credit_left_ mt">カード番号</dt>
    <dd class="credit_right_">
      <input class="point_text" id="credit_card_num2" type="text" name="giftcardnum" value="" size="20" maxlength="16">
      <input id="credit_card_num2_1" type="image" src="/new_img/sys/etc_card_05.png" name="reference" alt="残高照会" onclick="document.frm.action = '/shop/order/method.aspx'"/>
      <input type="hidden" name="reference.x" value="true">

    </dd>
  </dl>
  <dl class="credit_list_">
    <dt class="credit_left_ mt">PIN番号</dt>
    <dd class="credit_right_">
      <input class="point_text" id="credit_pin_card_num" type="text" name="pin" value="" size="10" maxlength="8">

    </dd>
  </dl>
  <dl class="credit_list_">
    <dt class="credit_left_ mt">使用金額</dt>
    <dd class="credit_right_">
      <ul class="pointList_">
        <li class="point_item_">
          <input class="point_input" name="giftpay" type="radio" id="giftpay_0" value="0" checked="true" onclick="click_UseGiftPayRadio();">
          <label class="point_label" for="giftpay_0">全額使用する</label>
        </li>
        <li class="point_item_">
          <input class="point_input" name="giftpay" type="radio" id="giftpay_1" value="1"  onclick="click_UseGiftPayRadio();">
          <label class="point_label" for="giftpay_1">使用額を指定する
          ￥<input class="point_num" type="text" name="giftprice" id="giftprice_num" value=""  size="10" maxlength="7" onfocus="focus_UseGiftPriceNum();" style="background-color:#dedede;">
          </label>
        </li>
      </ul>



<p class="price_text_area">ギフトカードの残高全てを使用する場合は、「全額使用する」を選択してください。
<br>一部ギフトカードの残高を使用する場合は、「使用額を指定する」を選択してください。
<br>ギフトカード残高が購入金額に満たない場合は、残金を他のお支払方法より選択いただく必要がございます。
<br>ご利用になりましたギフトカードは、商品お受け取りまでお持ちいただくようお願い致します。
</p>

    </dd>
  </dl>
</div>

<script type="text/javascript">
<!--
click_UseGiftPayRadio();
-->
</script>





<div style="border:none;padding:0px;margin-top:0;">
<div class="border_area method_rH"><strong class="dispNone method_rH method_ttl">d払い(ドコモ)</strong>
  <div class="dispNone method_rH method_text">■お支払い額に応じて、dポイントを貯めることも使うことも出来るお得で便利なドコモ決済サービスです。<br>■お支払いは、月々の電話料金合算払いの他、クレジットカードでのお支払いも可能ですので、ドコモ以外の方でもご利用頂けます。<br> 　※ドコモ以外の方がご利用の際は、dアカウントが必要となります。</div>
</div>
<div class="border_area method_r7"><strong class="dispNone method_r7 method_ttl">クレジットカード</strong>
  <div class="dispNone method_r7 method_text">
    <p><img src="/new_img/sys/guide_card.png" alt=""></p>
    <p style="margin: 15px 0px 10px 0px;">■当サイトにてご利用いただけるクレジットは上記のカードに限らせていただきます。<br> 　支払い方法：翌月1回払い</p> ■代金は各カード会社とのご契約口座から引き落としになります。<br> 　・カードのご利用は名義人ご本人に限らせていただきます。<br> 　・カードがご利用できない場合は、ご自身でカード会社にお問合せお願い致します。
  </div>
</div>
<div class="border_area method_r2"><strong class="dispNone method_r2 method_ttl">代金引換</strong>
  <div class="dispNone method_r2 method_text">・代金引換手数料￥380（税込）が商品代金に加算されます。商品到着時に配達員にお支払ください。<br></div>
</div>
<div class="border_area method_rD"><strong class="dispNone method_rD method_ttl">後払い（GMOペイメントサービス株式会社が提供する後払いサービスを導入しております。）</strong>
  <div class="dispNone method_rD method_text">■後払い手数料￥200（税込）が商品代金に加算されます。<br>■ご利用限度額はGMOペイメントサービス株式会社の後払い累計で、￥55,000（税込）です。また、ご利用に際して、審査がございます。<br>■商品受取後、別送でＧＭＯペイメントサービス株式会社から請求書が届きます。<br>■請求書発効日から14日以内にお支払ください。<br>■全国主要のコンビニ・郵便局・銀行でお支払いただけます。<br>■ご利用の端末(パソコン、スマートフォン)の言語の設定が日本語もしくは、English以外の場合 GMO後払いの支払方法をご利用できないことがございますので、ご了承願います。<br> GMO後払いをご利用の場合は、言語の設定を日本語もしくは、Englishに設定お願い致します。</div>
</div>
<div class="border_area method_rG"><strong class="dispNone method_rG method_ttl">ギフトカード</strong>
  <div class="dispNone method_rG method_text">
    <p style="margin: 15px 0px 10px 0px;">■当オンラインストア(ネット通販）でのギフトカードは、下記の「ABC-MART GIFT CARD」のみご利用可能となります。<br></p>
    <p style="margin: 15px 0px 15px 30px;"><img src="/new_img/sys/gift_card.png" alt=""></p> ■ご利用に関しては、<a href="/shop/contents2/giftcard.aspx" style="text-decoration:underline">ご利用約款</a>に同意いただいたものと致します。<br> 　・ご利用は、1注文につきギフトカード1枚までとなります。複数枚を1注文にてご利用頂くことは出来ません。<br> 　・ご利用のギフトカード金額が購入決済金額に満たない場合は、購入残金を他のお支払方法より選択いただく必要がございます。 <br> 　・ご利用になられたギフトカードは商品お受け取り完了までお持ち下さい。
  </div>
</div>
</div>






</div>

<div class="method_order_">
  <h2 class="common_headline2_">ご注文商品</h2>
  <table class="formlist_ cartlist_">
    <input type="hidden" name="refresh" value="true">
    <tbody>

<tr>
  <td class="img_">
    <input type="hidden" name="rowcart1" value="32012170">
    <input type="hidden" name="rowgoods1_1" value="6025230001016">
    <input type="hidden" name="rowds_warehouse1" value="01">
    
    <img src="https://img.apim.abc-mart.biz/img/6025/6025230001/602523000101.jpg?sr.dw=713" alt="レディース【CONVERSE】 コンバース AS S MULE SLIP OX オールスター S ミュール スリップ OX 31301612 WHITE 5H(24.5cm)">
    
  </td>
  <td class="name_">
    <div class="name_">
      <div class="name1_">
    
        レディース【CONVERSE】 コンバース AS S MULE SLIP OX オールスター S ミュール スリップ OX 31301612 WHITE 5H(24.5cm)<br>
    
        <p class="name1_color_">カラー：<span class="name1_color_value">WHITE</span></p>
        <p class="name1_size_">サイズ：<span class="name1_size_value_">5H(24.5cm)</span></p>

数量：1<input value="1" type="hidden" name="qty1_1">
      </div>
    </div>
    <p class="wrapping">ギフトラッピング</p>
    <div class="select_area wrap">
    
    <select class="selecter" name="wrap1_1"><option value="0" selected>ラッピング無し</option><option value="1">ラッピング：1</option></select><br>
    
    



    </div>
    <p class="wrapping_note_">※ギフトラッピング(1点につき￥110(税込))<br>不要な方は「ラッピング無し」のままで注文を進めてください。</p>
  </td>

</tr>



<tr>
  <td class="img_">
    <input type="hidden" name="rowcart2" value="32012171">
    <input type="hidden" name="rowgoods1_2" value="6025230001012">
    <input type="hidden" name="rowds_warehouse1" value="01">
    
    <img src="https://img.apim.abc-mart.biz/img/6025/6025230001/602523000101.jpg?sr.dw=713" alt="レディース【CONVERSE】 コンバース AS S MULE SLIP OX オールスター S ミュール スリップ OX 31301612 WHITE 3H(22.5cm)">
    
  </td>
  <td class="name_">
    <div class="name_">
      <div class="name1_">
    
        レディース【CONVERSE】 コンバース AS S MULE SLIP OX オールスター S ミュール スリップ OX 31301612 WHITE 3H(22.5cm)<br>
    
        <p class="name1_color_">カラー：<span class="name1_color_value">WHITE</span></p>
        <p class="name1_size_">サイズ：<span class="name1_size_value_">3H(22.5cm)</span></p>

数量：1<input value="1" type="hidden" name="qty1_2">
      </div>
    </div>
    <p class="wrapping">ギフトラッピング</p>
    <div class="select_area wrap">
    
    <select class="selecter" name="wrap1_2"><option value="0" selected>ラッピング無し</option><option value="1">ラッピング：1</option></select><br>
    
    



    </div>
    <p class="wrapping_note_">※ギフトラッピング(1点につき￥110(税込))<br>不要な方は「ラッピング無し」のままで注文を進めてください。</p>
  </td>

</tr>



    </tbody>
  </table>
</div>


<div class="submit_ cart">
  <a href="/shop/cart/cart.aspx"><img src="/new_img/sys/button/back.png" alt="戻る"></a>
  <!--
  <a id="FormAssist_submit_err" href="#"><img src="/new_img/sys/button/next.png" style="width:undefinedpx;height:undefinedpx;border:0;"></a>
  -->

 <input type="image" name="submit" src="/new_img/sys/button/next.png" alt="次へ" class="confirmation_btn" id="FormAssist_submit">

</div>
<script type="text/javascript">
jQuery(document).ready(function() {
click_UsePointRadio();
});
</script>
<!--配送希望日時-->
<style>
p#haisouhouhouButton0::before {
content: "ご希望がある場合は、次ページの備考欄にご記入ください。";
display: block;
margin-bottom: 10px;
font-weight: bold;
}

p.close::after {
content: "＞";
margin-left: 10px;
line-height: 1em;
transform: rotate(90deg);
display: inline-block;
cursor: pointer;
}

p.open::after {
content: "＞";
margin-left: 10px;
line-height: 1em;
transform: rotate(-90deg);
display: inline-block;
cursor: pointer;
padding-left: 2px;
}
</style>
</form>
</div>
</section>

</div>
</div>
<!-- END container_-->

<script type='text/javascript' >
	jQuery(document).ready(function(){
		getSearchList()
	});
</script>


<script type='text/javascript' src='https://formassist.jp/FormAssist_tag.js?user=abcm&num=20101217212624'></script>


<!-- Rendering BodyContents End -->
  

    

    

    
      <!-- YTM -->
<script type="text/javascript">
  (function () {
    var tagjs = document.createElement("script");
    var s = document.getElementsByTagName("script")[0];
    tagjs.async = true;
    tagjs.src = "//s.yjtag.jp/tag.js#site=t07geDQ&referrer=" 
    + encodeURIComponent(document.location.href) + "";
    s.parentNode.insertBefore(tagjs, s);
  }());
</script>
<noscript>
  <iframe src="//b.yjtag.jp/iframe?c=t07geDQ" width="1" height="1" frameborder="0" scrolling="no" marginheight="0" marginwidth="0"></iframe>
</noscript>

    
  


  
<!--
<script language="JavaScript">

if(navigator.userAgent.indexOf("MSIE") == -1){
document.write('<script type="text/javascript" charset="UTF-8" src="//navicast.jp/NavicastApi.js?abc-mart"></script>');
}
</script>
-->

<script language='JavaScript' type='text/javascript' src='https://track.mk.impact-ad.jp/ad/js/cjs.js'></script>
<script language='JavaScript' type='text/javascript'><!--
admage_onetag('https://track.mk.impact-ad.jp/ad/p/ot', '_aid=52&_oid=185',false);
 --></script>
<noscript>
<iframe src='https://track.mk.impact-ad.jp/ad/p/ot?_aid=52&_oid=185' width='0' height='0' marginwidth='0' marginheight='0' hspace='0' vspace='0' frameborder='0' scrolling='no' bordercolor='#000000'></iframe>
</noscript>


<script type='text/javascript'>
<!--
<!-- BEGIN: Google Trusted Stores -->

    var gts = gts || [];
    var goods = setGoods_gts();
    
    gts.push(["id", "235538"]);
    gts.push(["locale", "ja_JP"]);

    if (goods != undefined){
    gts.push(["google_base_offer_id",goods]);
    gts.push(["google_base_subaccount_id", "8895664"]);
    gts.push(["google_base_country", "JP"]);
    gts.push(["google_base_language", "ja"]);
    }else{
    gts.push(["google_base_offer_id", '' ]);
    gts.push(["google_base_subaccount_id", '']);
    gts.push(["google_base_country", '']);
    gts.push(["google_base_language", '']);
    }

  (function() {
    var scheme = (("https:" == document.location.protocol) ? "https://" : "http://");
    var gts = document.createElement("script");
    gts.type = "text/javascript";
    gts.async = true;
    gts.src = scheme + "www.googlecommerce.com/trustedstores/gtmp_compiled.js";
    var s = document.getElementsByTagName("script")[0];
    s.parentNode.insertBefore(gts, s);
  })();

-->
</script>
<!-- END: Google Trusted Stores -->


  


<script type="text/javascript">
var google_tag_params = {
ecomm_prodid: '',
ecomm_pagetype: 'other',
ecomm_totalvalue: ''
};
</script>



<script>
dataLayer = [{
  google_tag_params: window.google_tag_params
}];
</script>

<!-- Google Tag Manager -->
<noscript><iframe src="//www.googletagmanager.com/ns.html?id=GTM-KV38N7"
height="0" width="0" style="display:none;visibility:hidden"></iframe></noscript>
<script>(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({'gtm.start':
new Date().getTime(),event:'gtm.js'});var f=d.getElementsByTagName(s)[0],
j=d.createElement(s),dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src=
'//www.googletagmanager.com/gtm.js?id='+i+dl;f.parentNode.insertBefore(j,f);
})(window,document,'script','dataLayer','GTM-KV38N7');</script>
<!-- End Google Tag Manager -->

</body>
</html>

'''
import sys
def testCartPage():
    resp = BeautifulSoup(text.encode('utf-8'), 'html.parser')
    cartlistTag = resp.find('table',attrs={'class':"formlist_ cartlist_"})
    paydata={}
    if cartlistTag:
        trTags = cartlistTag.findAll('tr')
        for trTag in trTags:
            #tdtag = trTag.find('td',attrs={'class':'img_'})
            inputTags = trTag.findAll({'input','select'})
            for inputTag in inputTags:
                try:
                    paydata[inputTag['name']]=inputTag['value']
                except Exception as identifier:
                    paydata[inputTag['name']]='0'
                    print(inputTag['name'])


def testOrderPage():
    step3='''
<!DOCTYPE html>
<html lang="ja">
<head>
<meta content="text/html; charset=utf-8" http-equiv="Content-Type"/>
<title>ご注文内容の確認 | ABC-MART 【公式通販】 </title>
<meta content="【ABC-MART公式通販】をお探しならこちらのページをどうぞ。ABC-MARTは幅広い品揃えで、お買い得なセール商品も多数取り揃えています。税込5,000円以上なら送料無料！" name="description"/>
<meta content="靴,シューズ,スニーカー,通販,通信販売,ABCマート, ABC MART,エービーシーマート,あｂｃ" name="keywords"/>
<meta content="text/html; charset=utf-8" http-equiv="Content-Type"/>
<meta content="text/css" http-equiv="content-style-type"/>
<link href="/new_css/reset.css" media="all" rel="stylesheet" type="text/css"/>
<link href="/new_css/layout/s_lmr.css" media="all" rel="stylesheet" type="text/css"/>
<link href="/new_css/common.css" media="all" rel="stylesheet" type="text/css"/>
<link href="/new_css/sidebox.css" media="all" rel="stylesheet" type="text/css"/>
<link href="/new_css/category.css" media="all" rel="stylesheet" type="text/css"/>
<link href="/new_css/goods.css" media="all" rel="stylesheet" type="text/css"/>
<link href="/new_css/order.css" media="all" rel="stylesheet" type="text/css"/>
<link href="/new_css/customer.css" media="all" rel="stylesheet" type="text/css"/>
<link href="/new_css/etc.css" media="all" rel="stylesheet" type="text/css"/>
<link href="/new_css/quickorder.css" media="all" rel="stylesheet" type="text/css"/>
<link href="/new_css/userreview.css" media="all" rel="stylesheet" type="text/css"/>
<link href="/new_css/core.css" media="all" rel="stylesheet" type="text/css"/>
<link href="/new_css/skin.css" media="all" rel="stylesheet" type="text/css"/>
<link href="/new_css/dropframe.css" media="all" rel="stylesheet" type="text/css"/>
<link href="/new_css/freepage.css" media="all" rel="stylesheet" type="text/css"/>
<link href="/new_css/slick-theme.css" rel="stylesheet" type="text/css"/>
<link href="/new_css/slick.css" rel="stylesheet" type="text/css"/>
<link href="/new_css/user.css" media="all" rel="stylesheet" type="text/css"/>
<link href="/new_css/ui-lightness/jquery-ui.css" media="all" rel="stylesheet" type="text/css"/>
<meta content="text/javascript" http-equiv="content-script-type"/>
<script language="JavaScript" src="/new_js/jquery-3.4.1.min.js" type="text/javascript"></script>
<script language="JavaScript" src="/new_js/jquery-migrate-1.4.1.min.js" type="text/javascript"></script>
<script language="JavaScript" src="/new_js/jquery-migrate-3.1.0.min.js" type="text/javascript"></script>
<script src="/new_js/lazyload.min.js"></script>
<script language="JavaScript" src="/new_js/slick.min.js" type="text/javascript"></script>
<script language="JavaScript" src="/new_js/common.js" type="text/javascript"></script>
<script src="/new_js/user.js"></script>
<script language="JavaScript" src="/js/jquery-ui.js" type="text/javascript"></script>
<script language="JavaScript" src="/new_js/lookupzip.js" type="text/javascript"></script>
<link href="/topic/feed.rss" rel="alternate" title="ecbeing topic feed" type="application/rss+xml"/>
<link href="/favicon.ico" rel="SHORTCUT ICON"/>
<link href="https://fonts.googleapis.com/css?family=Montserrat:600,700&amp;display=swap" rel="stylesheet"/>
<link href="/css/core.css" rel="stylesheet" type="text/css">
<link href="/css/skin.css" rel="stylesheet" type="text/css">
</link></link></head>
<body>
<!-- Rendering BodyContents Start -->
<div class="container_">
<!-- contents_-->
<div class="contents_">
<nav class="temp-path">
<ul>
<li><a href="/shop/?sgender=d">トップ</a></li>
<li>
<p>&gt;</p>
</li>
<li>
<p>ご注文内容の確認</p>
</li>
</ul>
</nav>
<div class="step3 order_ col1_">
<h1 class="heading_ttl-lv1">ご注文内容の確認</h1>
<div class="order_flow_"><img alt="STEP3 ご注文内容の確認" src="/new_img/sys/order_step3.png"/></div>
<script type="text/javascript">
            <!--
            var iPrevTime = null;
            function formSubmit() {
              if( iPrevTime == null ) { iPrevTime = 1; return true; }
              else { return false; }
            }
            -->
          </script>
<form action="/shop/order/estimate.aspx" class="step3-block" id="frmSales" method="post" onsubmit="return formSubmit();">
<div class="step3-blockWrapper">
<div class="step3-leftBlock">
<div class="step3-2block">
<div class="step3-block">
<h2 class="common_headline2_"> ご注文者</h2>
<p class="step3-block_para">  ｙｏｕ ｚｉ 様</p>
<div class="step3-block_body">
<p class="step3-block_para">〒 828-8768 北海道ｆａｗｅｇｂａｒｅｆａｗｅｇｒｅａｇ<br/>TEL：04-9769-5645</p>
</div>
</div>
<div class="step3-block">
<h2 class="common_headline2_">お届け先



                    <a class="step3-changebtn" href="/shop/order/method.aspx?estimate=7842242&amp;dest_no=0&amp;d1=0&amp;d2=0#address1">変更</a>
</h2>
<p class="step3-block_para">  ｙｏｕ ｚｉ 様</p>
<div class="step3-block_body">
<p class="step3-block_para">〒 828-8768 北海道ｆａｗｅｇｂａｒｅｆａｗｅｇｒｅａｇ<br/>TEL：04-9769-5645</p>
</div>
</div>
<div class="step3-block">
<h2 class="common_headline2_">ポイント利用



                    <a class="step3-changebtn" href="/shop/order/method.aspx?estimate=7842242&amp;dest_no=0&amp;d1=0&amp;d2=0#method_point">変更</a></h2>
<div class="step3-block_body">
<p class="step3-block_para">ご利用ポイント：<span class="now-point">0pt</span><br/>
                      ポイント残高：<span>0pt</span><br/>
                      今回発生予定ポイント：<span>60pt</span>
</p>
</div>
</div>
<div class="step3-block">
<h2 class="common_headline2_">クーポン利用



                    <a class="step3-changebtn" href="/shop/order/method.aspx?estimate=7842242&amp;dest_no=0&amp;d1=0&amp;d2=0#method_coupon">変更</a>
</h2>
<div class="step3-block_body">
</div>
</div>
<div class="step3-block">
<h2 class="common_headline2_">お支払い方法



                    <a class="step3-changebtn" href="/shop/order/method.aspx?estimate=7842242&amp;dest_no=0&amp;d1=0&amp;d2=0#method_pay">変更</a></h2>
<div class="step3-block_body">
<p class="step3-block_para">代金引換</p>
<p class="step3-block_para text-red">ラッピングをご希望の方は変更ボタンより追加をお願いします。</p>
</div>
</div>
<script>
                jQuery(function () {
                  var jQuerywindow = jQuery(window),
                    jQueryhtml = jQuery('html'),
                    jQuerybody = jQuery('body'),
                    jQueryoverlay_1 = jQuery('.overlay_1'),
                    scrollbar_width = window.innerWidth - document.body.scrollWidth,
                    touch_start_y;
                  var agent = navigator.userAgent;
                  if (agent.search(/iPhone/) != -1) {
                    var iphone_zoom = jQuery(window).width();
                    var iphone_zoomout = 320 / iphone_zoom;
                    jQuerywindow.on('touchstart', function (event) {
                      touch_start_y = event.originalEvent.changedTouches[0].screenY / iphone_zoomout;
                    });
                  } else {
                    jQuerywindow.on('touchstart', function (event) {
                      touch_start_y = event.originalEvent.changedTouches[0].screenY;
                    });
                  }
                  jQuery('.popup-modal-1').on('click', function () {
                    jQuerywindow.on('touchmove.noscroll', function (event) {
                      var overlay_1 = jQueryoverlay_1[0],
                        current_y = event.originalEvent.changedTouches[0].screenY,
                        height = jQueryoverlay_1.outerHeight(),
                        is_top = touch_start_y <= current_y && overlay_1.scrollTop === 0,
                        is_bottom = touch_start_y >= current_y && overlay_1.scrollHeight - overlay_1.scrollTop === height * iphone_zoomout;
                      if (is_top || is_bottom) {
                        event.preventDefault();
                      }
                    });
                    jQuery('body').css('overflow', 'hidden');
                    if (scrollbar_width) {
                      //jQueryhtml.css('padding-right', scrollbar_width);
                    }
                    jQueryoverlay_1.fadeIn(300);
                  });
                  var closeModal = function () {
                    jQuerybody.removeAttr('style');
                    jQuerywindow.off('touchmove.noscroll');
                    jQueryoverlay_1.animate({
                      opacity: 0
                    }, 300, function () {
                      jQueryoverlay_1.scrollTop(0).hide().removeAttr('style');
                      //jQueryhtml.removeAttr('style');
                    });
                  };
                  jQueryoverlay_1.on('click', function (event) {
                    if (!jQuery(event.target).closest('.modal').length) {
                      closeModal();
                    }
                  });
                  jQuery('.close_button').on('click', function () {
                    closeModal();
                  });
                });
              </script>
</div> <!-- end step3-2block -->
<div class="step3-1block">
<div class="step3-block">
<h2 class="common_headline2_">ご注文商品<a class="step3-changebtn" href="/shop/cart/cart.aspx">変更</a></h2>
<ul class="step3-block_list">
<li class="step3-block_item"><img alt="レディース【CONVERSE】 コンバース AS S MULE SLIP OX オールスター S ミュール スリップ OX 31301612 WHITE 5H(24.5cm)" class="lazyload step3-block_itemImage" data-src="https://img.apim.abc-mart.biz/img/6025/6025230001/602523000101.jpg?sr.dw=713" src="https://img.apim.abc-mart.biz/img/6025/6025230001/602523000101.jpg?sr.dw=713">
<noscript><img alt="レディース【CONVERSE】 コンバース AS S MULE SLIP OX オールスター S ミュール スリップ OX 31301612 WHITE 5H(24.5cm)" class="step3-block_itemImage" src="https://img.apim.abc-mart.biz/img/6025/6025230001/602523000101.jpg?sr.dw=713"/></noscript>
<div class="step3-block_itembody">
<p class="step3-block_itemname">レディース【CONVERSE】 コンバース AS S MULE SLIP OX オールスター S ミュール スリップ OX 31301612 WHITE 5H(24.5cm)</p>
<p class="step3-block_itemdata">
<span class="step3-block_data__color">カラー：WHITE</span>
<span class="step3-block_data__size">サイズ：5H(24.5cm)</span>
<span class="step3-block_data__quantity">数量：1</span>
</p>
<p class="step3-block_itemgift">ギフトラッピング数量：0</p>
</div>
<div class="step3-block_itemsubtotal">
<p class="step3-block_itemvalue"><span class="value_title">合計：</span><span class="value_num">￥3,289</span><span class="value_unit">(税込)</span></p>
</div>
</img></li>
<li class="step3-block_item"><img alt="レディース【CONVERSE】 コンバース AS S MULE SLIP OX オールスター S ミュール スリップ OX 31301612 WHITE 3H(22.5cm)" class="lazyload step3-block_itemImage" data-src="https://img.apim.abc-mart.biz/img/6025/6025230001/602523000101.jpg?sr.dw=713" src="https://img.apim.abc-mart.biz/img/6025/6025230001/602523000101.jpg?sr.dw=713"/>
<noscript><img alt="レディース【CONVERSE】 コンバース AS S MULE SLIP OX オールスター S ミュール スリップ OX 31301612 WHITE 3H(22.5cm)" class="step3-block_itemImage" src="https://img.apim.abc-mart.biz/img/6025/6025230001/602523000101.jpg?sr.dw=713"/></noscript>
<div class="step3-block_itembody">
<p class="step3-block_itemname">レディース【CONVERSE】 コンバース AS S MULE SLIP OX オールスター S ミュール スリップ OX 31301612 WHITE 3H(22.5cm)</p>
<p class="step3-block_itemdata">
<span class="step3-block_data__color">カラー：WHITE</span>
<span class="step3-block_data__size">サイズ：3H(22.5cm)</span>
<span class="step3-block_data__quantity">数量：1</span>
</p>
<p class="step3-block_itemgift">ギフトラッピング数量：0</p>
</div>
<div class="step3-block_itemsubtotal">
<p class="step3-block_itemvalue"><span class="value_title">合計：</span><span class="value_num">￥3,289</span><span class="value_unit">(税込)</span></p>
</div>
</li>
</ul>
</div>
<h2 class="common_headline2_">備考欄</h2>
<p class="step3-block_para">上記、ご注文内容で注文を確定します。
  <br/>ご注文内容に関してのご要望がございましたら下記にご記入ください。
  <br/>「ご注文」ボタン（または[d払い(ドコモ)へ]ボタン）をクリックすると注文を確定します。
  <br/>ラッピングをご希望の方は「お支払い方法」の変更ボタンより追加をお願いします。
</p>
<input name="estimate" type="hidden" value="7842242"/>
<input name="gc" type="hidden" value=""/>
<input name="p" type="hidden" value=""/>
<textarea class="step3-block_textarea" cols="80" name="comment" rows="5" tabindex="1"></textarea>
<div class="step3-block">
<h2 class="common_headline2_">ご注意</h2>
<ul class="step3-block_attention">
<li class="step3-block_attentionItem">※沖縄県内へのお届けに関しては、送料とは別に中継料(￥1,100（税込）)がかかります。尚、中継料(￥1,100（税込）)は送料欄に記載されます。 　詳しくは<a href="https://www.abc-mart.net/shop/pages/guide_order_delivery.aspx" target="_blank">こちら</a>をご覧ください。</li>
<li class="step3-block_attentionItem">※高額のご注文に関しましてはご本人様確認をとらせて頂いてからの出荷となります。予めご了承ください。</li>
<li class="step3-block_attentionItem">※ご注文確定日の翌日出荷予定となります。</li>
<li class="step3-block_attentionItem">※代金引換決済で複数のご注文は出荷が遅れる場合がございます。</li>
<li class="step3-block_attentionItem">※手続きが完了した注文同士をまとめることはシステム上お受けできませんので、複数商品をご注文される場合はご注意ください。</li>
<li class="step3-block_attentionItem">※代引き手数料や送料は1注文ごとにかかりますので、予めご了承ください。</li>
<li class="step3-block_attentionItem">※ご注文日の翌日、またはご注文日から9日間を超えるご指定はお受けできませんので、こちらも合わせてご了承頂きますよう、<br/>お願い申し上げ ます。</li>
<li class="step3-block_attentionItem">※ご利用になりましたギフトカードは、商品お受け取りまでお持ちいただくようお願い致します。</li>
<li class="step3-block_attentionItem"><br/></li>
<li class="step3-block_attentionItem">※梱包について</li>
</ul>
</div>
<div class="refound-item_inner">
<div class="refound-item-img">
<img alt="梱包について" src="https://img.abc-mart.net/new_img/usr/freepage/presentwrapping/konpou.jpg"/>
</div>
<div class="refound-item-comment">
<p class="">
                弊社は環境に配慮し、簡易包装にてお届けしております。<br/>
                そのため、商品本体には影響はございませんが、配送中に化粧箱等に多少のシワ、変形等が発生する場合がございます。<br/>
                予めご了承の上、ご注文をお願い致します。
            </p>
</div>
</div>
</div> <!-- end step3-1block -->
</div> <!-- end step3-leftBlock -->
<div class="step3-rightBlock">
<div class="submit_new_ submit_new_top js-order-side-area">
<div class="breakdown_area">
<div class="flex_text">
<p>商品合計</p>
<p class="flex_text_right"><span class="total_price">￥6,578</span><span class="total_unit">(税込)</span></p>
</div>
<div class="flex_text">
<p class="flex_text-small">送料</p>
<p class="flex_text_right"><span class="flex_text-small">￥0</span><span class="total_unit">(税込)</span></p>
</div>
<div class="flex_text">
<p class="flex_text-small">手数料</p>
<p class="flex_text_right"><span class="flex_text-small">￥380</span><span class="total_unit">(税込)</span></p>
</div>
<div class="flex_text">
<p class="flex_text-small">ラッピング代</p>
<p class="flex_text_right"><span class="flex_text-small">￥0</span><span class="total_unit">(税込)</span></p>
</div>
<div class="flex_text mt15">
<p class="flex_text-small">ポイント利用</p>
<p class="flex_text_right"><span class="flex_text-small">0pt</span><span class="total_unit"></span></p>
</div>
</div>
<div class="flex_text flex-align-c">
<p>合計</p>
<div class="flex_text_right"><span class="result_total_price">￥6,958</span>(税込)</div>
</div>
<div class="flex_text_right"><span class="point-red">ポイント</span><span class="point-red">60</span><span class="point-red">pt発生予定</span></div>
<div class="checkout_btn">
<input class="button_ confirmation_btn" id="FormAssist_submit" name="submit" src="/new_img/sys/button/btn_order_submit.png" tabindex="1" type="image" value="注文を確定する"/>
<script src="/new_js/cart_submit.js" type="text/javascript"></script>
<span class="checkout_btn_note"><span id="nowdt">10月22日までに出荷予定</span></span>
</div>
</div>
</div> <!-- end right block -->
</div> <!-- end step3-blockWrapper -->
</form></div> <!-- end step3 order_ col1_ -->

</div> <!-- END contents_-->
</div> <!-- END container_-->
<script src="https://formassist.jp/FormAssist_tag.js?user=abcm&amp;num=20101217212701" type="text/javascript"></script>
<!-- Rendering BodyContents End -->
<!-- YTM -->
<script type="text/javascript">
  (function () {
    var tagjs = document.createElement("script");
    var s = document.getElementsByTagName("script")[0];
    tagjs.async = true;
    tagjs.src = "//s.yjtag.jp/tag.js#site=t07geDQ&referrer="
    + encodeURIComponent(document.location.href) + "";
    s.parentNode.insertBefore(tagjs, s);
  }());
</script>
<noscript>
<iframe frameborder="0" height="1" marginheight="0" marginwidth="0" scrolling="no" src="//b.yjtag.jp/iframe?c=t07geDQ" width="1"></iframe>
</noscript>
<!--
<script language="JavaScript">

if(navigator.userAgent.indexOf("MSIE") == -1){
document.write('<script type="text/javascript" charset="UTF-8" src="//navicast.jp/NavicastApi.js?abc-mart"></script>');
}
</script>
-->
<script language="JavaScript" src="https://track.mk.impact-ad.jp/ad/js/cjs.js" type="text/javascript"></script>
<script language="JavaScript" type="text/javascript"><!--
admage_onetag('https://track.mk.impact-ad.jp/ad/p/ot', '_aid=52&_oid=185',false);
 --></script>
<noscript>
<iframe bordercolor="#000000" frameborder="0" height="0" hspace="0" marginheight="0" marginwidth="0" scrolling="no" src="https://track.mk.impact-ad.jp/ad/p/ot?_aid=52&amp;_oid=185" vspace="0" width="0"></iframe>
</noscript>
<script type="text/javascript">
<!--
<!-- BEGIN: Google Trusted Stores -->

    var gts = gts || [];
    var goods = setGoods_gts();

    gts.push(["id", "235538"]);
    gts.push(["locale", "ja_JP"]);

    if (goods != undefined){
    gts.push(["google_base_offer_id",goods]);
    gts.push(["google_base_subaccount_id", "8895664"]);
    gts.push(["google_base_country", "JP"]);
    gts.push(["google_base_language", "ja"]);
    }else{
    gts.push(["google_base_offer_id", '' ]);
    gts.push(["google_base_subaccount_id", '']);
    gts.push(["google_base_country", '']);
    gts.push(["google_base_language", '']);
    }

  (function() {
    var scheme = (("https:" == document.location.protocol) ? "https://" : "http://");
    var gts = document.createElement("script");
    gts.type = "text/javascript";
    gts.async = true;
    gts.src = scheme + "www.googlecommerce.com/trustedstores/gtmp_compiled.js";
    var s = document.getElementsByTagName("script")[0];
    s.parentNode.insertBefore(gts, s);
  })();

-->
</script>
<!-- END: Google Trusted Stores -->
<script type="text/javascript">
var google_tag_params = {
ecomm_prodid: '',
ecomm_pagetype: 'other',
ecomm_totalvalue: ''
};
</script>
<script>
dataLayer = [{
  google_tag_params: window.google_tag_params
}];
</script>
<!-- Google Tag Manager -->
<noscript><iframe height="0" src="//www.googletagmanager.com/ns.html?id=GTM-KV38N7" style="display:none;visibility:hidden" width="0"></iframe></noscript>
<script>(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({'gtm.start':
new Date().getTime(),event:'gtm.js'});var f=d.getElementsByTagName(s)[0],
j=d.createElement(s),dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src=
'//www.googletagmanager.com/gtm.js?id='+i+dl;f.parentNode.insertBefore(j,f);
})(window,document,'script','dataLayer','GTM-KV38N7');</script>
<!-- End Google Tag Manager -->
</body>
</html>
'''
    resp = BeautifulSoup(step3.encode('utf-8'), 'html.parser')
    inputTags = resp.findAll('input',attrs={'type':"hidden"})
    paydata={}
    if inputTags:
        for inputTag in inputTags:
            try:
                paydata[inputTag['name']]=inputTag['value']
            except Exception as identifier:
                paydata[inputTag['name']]='0'
                print(inputTag['name'])
    print(paydata)
    estimateurl='https://www.abc-mart.net/shop/order/estimate.aspx?estimate={estimate}&pointpay={pointpay}&gc={gc}&p={p}&coupon={coupon}&dest_no={dest_no}'
    orderurl = estimateurl.format(estimate=paydata['estimate'],
                                      pointpay='',
                                      gc=paydata['gc'],
                                      p=paydata['p'],
                                      coupon='',
                                      dest_no='0')
    print(orderurl)

testOrderPage()