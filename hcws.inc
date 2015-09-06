<?php
// All functional php code end here.

function healthCareWorksheetForm(){
global $base_url;
	//Have to use the heredoc style
pdf_generator();

	$chronic_conditions=array('high blood pressure','high cholestrol','obesity','diabetes (type1 or 2)','health condition or previous heart attack','asthma','COPD','HIV/AIDS','cancer','Kidney disease','liver disease','peptic ulcer disease','irritable bowel disease (IBD)','multiple sclerosis','epilepsy','Parkinson\'s disease','rheumatoid arthritis','glaucoma','alcoholism','tabacco use(any form)','other drug use','schizophrenia','bipolar mood disorder');

	$checkboxes="";
	foreach($chronic_conditions as $value):
		$checkboxes.="<input type='checkbox' value='$value' name='chronic_conditions[]'> ".ucwords($value)."<br>";
    endforeach;

	$form_html=<<<xyz
	<div style='color:black;width:740px;margin:auto'>
	<form method='post' action='' id='health_care_worksheet_form'>
	<h1 style='color:#FF9200'>WHO'S ON YOUR PLAN</h1>
	<p>How many people will be covered by your plan? Count yourseld, along with any of your family members (including children) who will be on your insurance plan.</p>
	<div class='whos_on_your_plan' id='whos_on_your_plan' style='margin-left:10px;width:82%;display:inline-block'></div><input  type='text' value='1' name='whos_on_your_plan' class='value_box'><br>
	<div class='show_people_pics'><img src='$base_url/sites/all/modules/healthcareworksheet/images/greenman.png' class='green_man'></div>
	<h1 style='color:#FF9200'>My Health Care Needs</h1>
	<p># of regular doctor's office visits in the next year?</p>
	<div class='dont_know'>Don't<br>Know</div><div class='regular_office_visits' id='regular_office_visits' style='width:68%;display:inline-block'>
	</div><input  type='text' value='1' name='regular_office_visits' class='value_box'><br>

	<p># of specialist office visits in the next year? <br> EXAMPLES : Cardiologists, Endocrinologist</p>
	<div class='dont_know'>Don't<br>Know</div><div class='specialist_office_visits' id='specialist_office_visits' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='specialist_office_visits' class='value_box'><br>

	<p># of lab visits Blood /Draws.</p>
	<div class='dont_know'>Don't<br>Know</div><div class='lab_visits' id='lab_visits' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='lab_visits' class='value_box'><br>

    <p># of overnight hospitalizations with surgery.</p>
	<div class='dont_know'>Don't<br>Know</div><div class='overnight_hospitalization_with_surgery_visits' id='overnight_hospitalization_with_surgery_visits' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='overnight_hospitalization_with_surgery_visits' class='value_box'><br>

	<p># of overnight hospitalizations without surgery.</p>
	<div class='dont_know'>Don't<br>Know</div><div class='overnight_hospitalization_without_surgery_visits' id='overnight_hospitalization_without_surgery_visits' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='overnight_hospitalization_without_surgery_visits' class='value_box'><br>

	<p># of out patient procedures /Draws.</p>
	<div class='dont_know'>Don't<br>Know</div><div class='patient_procedures' id='patient_procedures' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='patient_procedures' class='value_box'><br>

    <p># of emergency room visits.</p>
	<div class='dont_know'>Don't<br>Know</div><div class='emergency_visits' id='emergency_visits' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='emergency_visits' class='value_box'><br>

	<p># of pregnancies in the next year.</p>
	<div class='dont_know'>Don't<br>Know</div><div class='pregnencies' id='pregnencies' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='pregnencies' class='value_box'><br>
    <p>List of any other medical expenses in the next year? <br>
    EXAMPLES : insulin pump, physical rehab, cancer treatment.
    </p>
    <textarea class='textarea' name='notes_whos_on_your_plan'></textarea>

	<h1 style='color:#FF9200'>MENTAL HEALTH CARE</h1>
	<p># of mental health care or counselling visits in the next year?</p>
	<div class='dont_know'>Don't<br>Know</div><div class='conselling_visits' id='conselling_visits' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='conselling_visits' class='value_box'><br>

	<p># of alcohol or drug rehab in the next year?</p>
	<div class='dont_know'>Don't<br>Know</div><div class='drug_rehab' id='drug_rehab' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='drug_rehab' class='value_box'><br>

	<p># of overnight psychiatric hospitalizations</p>
	<div class='dont_know'>Don't<br>Know</div><div class='overnight_psychiatric_hospitalizations' id='overnight_psychiatric_hospitalizations' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='overnight_psychiatric_hospitalizations' class='value_box'><br>

	<p>List of any other medical expenses in the next year?</p>
    <textarea class='textarea' name='notes_mental_health_care'></textarea>


    <h1 style='color:#FF9200'>MEDICATION AND SUPPLIES</h1>
	<p># of generic prescription medications filled every month?</p>
	<div class='dont_know'>Don't<br>Know</div><div class='generic_prescription_medications' id='generic_prescription_medications' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='generic_prescription_medications' class='value_box'><br>

	<p># of brand-name prescription medications filled every month?</p>
	<div class='dont_know'>Don't<br>Know</div><div class='brand_name_prescription_medications' id='brand_name_prescription_medications' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='brand_name_prescription_medications' class='value_box'><br>

	<p># of medical supplies purchased every month? EXAMPLES :syringes, diabetic test strips</p>
	<div class='dont_know'>Don't<br>Know</div><div class='medical_supplies_purchased' id='medical_supplies_purchased' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='medical_supplies_purchased' class='value_box'><br>

	<p>List of any other medical expenses in the next year?<br>EXAMPLES : oxygen, oxygen equipment.</p>
    <textarea class='textarea' name='notes_medication_and_supplies'></textarea>

    <h1 style='color:#FF9200'>VISION & HEARING CARE</h1>
	<p># of eye exams in the next year?</p>
	<div class='dont_know'>Don't<br>Know</div><div class='eye_exams' id='eye_exams' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='eye_exams' class='value_box'><br>

	<p># of eye glasses purchased in the next year?</p>
	<div class='dont_know'>Don't<br>Know</div><div class='eye_glasses' id='eye_glasses' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='eye_glasses' class='value_box'><br>

	<p># of contact lenses purchased in the next year?</p>
	<div class='dont_know'>Don't<br>Know</div><div class='contact_lenses' id='contact_lenses' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='contact_lenses' class='value_box'><br>

    <p># of eye surgeries in the next year?</p>
	<div class='dont_know'>Don't<br>Know</div><div class='eye_surgeries' id='eye_surgeries' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='eye_surgeries' class='value_box'><br>

	<p># of hearing exams in the next year?</p>
	<div class='dont_know'>Don't<br>Know</div><div class='hearing_exams' id='hearing_exams' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='hearing_exams' class='value_box'><br>

	<p># of hearing aids or batteries in the next year?</p>
	<div class='dont_know'>Don't<br>Know</div><div class='hearing_aids' id='hearing_aids' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='hearing_aids' class='value_box'><br><br>
    <p>List any other vision or hearing expenses in the next year: </p>
    <textarea class='textarea' name='notes_vision_hearing_care'></textarea>

    <h1 style='color:#FF9200'>DENTAL CARE </h1>
    <p># of the dental exams in the next year? </p>
	<div class='dont_know'>Don't<br>Know</div><div class='dental_exams' id='dental_exams' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='dental_exams' class='value_box'><br>

	<p># of teeth cleanings in the next year? </p>
	<div class='dont_know'>Don't<br>Know</div><div class='teeth_cleanings' id='teeth_cleanings' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='teeth_cleanings' class='value_box'><br>

	<p># of cavity fillings in the next year?</p>
	<div class='dont_know'>Don't<br>Know</div><div class='cavity_fillings' id='cavity_fillings' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='cavity_fillings' class='value_box'><br>

	<p># of root canals in the next year? </p>
	<div class='dont_know'>Don't<br>Know</div><div class='root_canals' id='root_canals' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='root_canals' class='value_box'><br>

	<p># of crown, bridges or dentures in the next year?</p>
	<div class='dont_know'>Don't<br>Know</div><div class='crown_bridges_dentures' id='crown_bridges_dentures' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='crown_bridges_dentures' class='value_box'><br>

	<p># of oral surgeries in the next year?</p>
	<div class='dont_know'>Don't<br>Know</div><div class='oral_surgeries' id='oral_surgeries' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='oral_surgeries' class='value_box'><br>

	<p># of braces or orthodontia in the next year? </p>
	<div class='dont_know'>Don't<br>Know</div><div class='braces_orthodontia' id='braces_orthodontia' style='width:68%;display:inline-block'></div><input  type='text' value='1' name='braces_orthodontia' class='value_box'><br>
    <br>
    <p>List any other dental expenses next year:</p>
	<textarea class='textarea' name='notes_dental_care'></textarea>


    <h1 style='color:#FF9200'>CHRONIC CONDITIONS</h1>
    <p>Does anyone who will be covered on your health insurance plan have :</p>

    $checkboxes
    <br>
    <p>OTHERS: </p>
    <textarea class='textarea' name='notes_chronic_conditions'></textarea>
    <div style='padding:45px;width:85%'>
<a href='javascript:void(0)' style='color:#FF9200;margin-right:150px;' class='submit_email'><img src='$base_url/sites/all/modules/healthcareworksheet/images/mail' class='green_man'> <span class='submit_Text'>Email as .PDF file </span></a>
<a href='javascript:void(0)' style='color:#FF9200' class='submit_print'><img src='$base_url/sites/all/modules/healthcareworksheet/images/mail' class='green_man'> <span class='submit_Text'>Print</span></a>
</div>
<input type='hidden' name='send_email'>
    </form>

</div>

<div class='fetch_email_popup'>
    <span class="modal_close" style='float:right;background: steelblue;color: white;padding: 5px 10px;border-radius: 50%;bottom: 14px;position: relative;left: 14px;'>X</span>
    <h4 style='color:steelblue;text-align:center;padding:5px;margin:5px;border-bottom:1px solid  lightgrey'>Send Email To</h4><br>
    <form method='post' action='' onsubmit='return false;'>
        <div style='text-align:center'>
            <br>
            <input type="email" id='report_email' required='required'><br><br><br>
            <input type='submit' class='app_info_disclaimer send_report_button' value="SEND REPORT">
          </div>
    </form>
</div>

<div class='black_mobile_overlay'></div>


  <link rel="stylesheet" href="//code.jquery.com/ui/1.11.4/themes/smoothness/jquery-ui.css">
  <script src="//code.jquery.com/jquery-1.10.2.js"></script>
  <script src="//code.jquery.com/ui/1.11.4/jquery-ui.js"></script>

  <script>
  var people="<img src='$base_url/sites/all/modules/healthcareworksheet/images/greenman.png' class='green_man'>";
   $( ".teeth_cleanings,.braces_orthodontia,.oral_surgeries,.crown_bridges_dentures,.root_canals,.cavity_fillings,.dental_exams,.hearing_aids,.hearing_exams,.eye_surgeries,.contact_lenses,.eye_exams,.eye_glasses,.generic_prescription_medications,.brand_name_prescription_medications,.medical_supplies_purchased,.conselling_visits,.drug_rehab,.overnight_psychiatric_hospitalizations,.emergency_visits,.pregnencies,.patient_procedures,.whos_on_your_plan,.specialist_office_visits,.regular_office_visits,.lab_visits,.overnight_hospitalization_with_surgery_visits,.overnight_hospitalization_without_surgery_visits" ).slider({
   	min:1,
   	max:10,
   	start:function(event,ui){
     // Nothing to be added here as of now.		
   	},
   	slide:function(event,ui){
   		people_html="";
   		this_id=$(this).attr('id');
        $("[name='"+this_id+"']").val(ui.value);

        //Special case

        if(this_id=='whos_on_your_plan')
   		{
   			for(i=1;i<=ui.value;i++){
   				people_html=people_html+people;
   			}

           $('.show_people_pics').html(people_html);

   		}

   	}
   });

$('.submit_print').click(function(){
	$('#health_care_worksheet_form').submit();
});


$('.submit_Text').click(function(){
	$('.fetch_email_popup,.black_mobile_overlay').fadeIn();
	$("html, body").animate({ scrollTop: 0 }, 600);

});

$('.modal_close').click(function(){
	$('.fetch_email_popup,.black_mobile_overlay').fadeOut();
});

$('.send_report_button').click(function(){
	if($('#report_email').val()){
    $("[name='send_email']").val($('#report_email').val());
    $('#health_care_worksheet_form').submit();
    }
});

</script>
<style>
.value_box{
	width:30px;
	display:inline-block;
	margin-left:20px;
	border:1px solid #9BD5C7;
	text-align:center;
	bottom:2px;
	position:relative;
}

.dont_know{
	display:inline-block;
	width: 12%;
	border: 2px solid lightgrey;
	text-align: center;
	margin-right: 20px;
	font-size: 13px;
	line-height: 17px;
	position: relative;
	top: 5px;
	color: grey;
}

p,h1{
	margin-top:10px;
	margin-bottom:10px;
}

.textarea{
	box-shadow:0 0 10px  #9BD5C7;
	width:82%;
	height:100px;
	display:block;
	border-radius:4px;
	padding:5px;
	font-family:trebuchet ms;
}

.green_man{
	margin-right:25px;
}

.submit_Text{
	bottom: 15px;
    position: relative;
    font-size: 20px;
}

.black_mobile_overlay{
    background: black;
    opacity: 0.7;
    height:100%;
    width:100%;
    position: fixed;
    z-index: 500;
    top:0;
    left:0;
    display: none;
}

.fetch_email_popup{
//border:10px solid black;
background: white;
padding:0px;
height:250px;
width: 350px;
position: absolute;
top:30%;
left:36%;
display: none;
z-index: 501;
border-radius: 10px;

}
</style>
xyz;

	return $form_html;
}

function pdf_generator(){
	global $base_url;
	$base_path=getcwd();
	error_reporting(~E_NOTICE);
	if($_POST['whos_on_your_plan']):

	//some conditions related to the  textareas they may come empty:
	if(!$_POST['notes_whos_on_your_plan'])
	$_POST['notes_whos_on_your_plan']="-Not Applicable-";	

    if(!$_POST['notes_mental_health_care'])
	$_POST['notes_mental_health_care']="-Not Applicable-";	
   
    if(!$_POST['notes_medication_and_supplies'])
	$_POST['notes_medication_and_supplies']="-Not Applicable-";

    if(!$_POST['notes_vision_hearing_care'])
	$_POST['notes_vision_hearing_care']="-Not Applicable-";

    if(!$_POST['notes_dental_care'])
	$_POST['notes_dental_care']="-Not Applicable-";

    if(!$_POST['notes_chronic_conditions'])
	$_POST['notes_chronic_conditions']="-Not Applicable-";
    		
    $page1=<<<xyz
    <h1 style="color:grey;font-size:20px">HEALTH CARE WORKSHEET</h1>
    <table style="width:100%" cellpadding="2" >
    <tr><th colspan="3" style="color:orange;margin-bottom:10px;text-decoration:underline">WHO'S ON YOUR PLAN</th></tr>
    <tr><td style="width:85%">How many people will be covered by your plan? Count yourseld, along with any of your family members (including children) who will be on your insurance plan.</td>
    <td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['whos_on_your_plan']}</td></tr>

    <tr><th colspan="3" style="color:orange;margin-bottom:10px;padding-top:20px;text-decoration:underline">MY HEALTH CARE NEEDS</th></tr>
    <tr><td style="width:85%"># of regular doctor's office visits in the next year?</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['regular_office_visits']}</td></tr>
    <tr><td style="width:85%"># of specialist office visits in the next year? EXAMPLES : Cardiologists, Endocrinologist</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['specialist_office_visits']}</td></tr>
    <tr><td style="width:85%"># of lab visits Blood /Draws.</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['lab_visits']}</td></tr>
    <tr><td style="width:85%"># of overnight hospitalizations with surgery.</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['overnight_hospitalization_with_surgery_visits']}</td></tr>
    <tr><td style="width:85%"># of overnight hospitalizations without surgery.</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['overnight_hospitalization_without_surgery_visits']}</td></tr>
    <tr><td style="width:85%"># of out patient procedures /Draws.</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['patient_procedures']}</td></tr>
    <tr><td style="width:85%"># of emergency room visits.</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['emergency_visits']}</td></tr>
    <tr><td style="width:85%"># of pregnancies in the next year.</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['pregnencies']}</td></tr>
    <tr><td colspan="3">List of any other medical expenses in the next year? EXAMPLES : insulin pump, physical rehab, cancer treatment.</td></tr>
    <tr><td colspan="3">Answer : {$_POST['notes_whos_on_your_plan']}</td></tr>


    <tr><th colspan="3" style="color:orange;margin-bottom:10px;padding-top:20px;text-decoration:underline">MENTAL HEALTH CARE</th></tr>
    <tr><td style="width:85%"># of mental health care or counselling visits in the next year?</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['conselling_visits']}</td></tr>
    <tr><td style="width:85%"># of alcohol or drug rehab in the next year?</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['drug_rehab']}</td></tr>
    <tr><td style="width:85%"># of overnight psychiatric hospitalizations</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['overnight_psychiatric_hospitalizations']}</td></tr>
    <tr><td colspan="3">List of any other medical expenses in the next year?</td></tr>
    <tr><td colspan="3">Answer : {$_POST['notes_mental_health_care']}</td></tr>


    <tr><th colspan="3" style="color:orange;margin-bottom:10px;padding-top:20px;text-decoration:underline">MEDICATION AND SUPPLIES</th></tr>
    <tr><td style="width:85%"># of generic prescription medications filled every month?</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['generic_prescription_medications']}</td></tr>
    <tr><td style="width:85%"># of brand-name prescription medications filled every month?</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['brand_name_prescription_medications']}</td></tr>
    <tr><td style="width:85%"># of medical supplies purchased every month? EXAMPLES :syringes, diabetic test strips</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['medical_supplies_purchased']}</td></tr>
    <tr><td colspan="3">List of any other medical expenses in the next year? EXAMPLES : oxygen, oxygen equipment.</td></tr>
    <tr><td colspan="3">Answer : {$_POST['notes_medication_and_supplies']}</td></tr>


    <tr><th colspan="3" style="color:orange;margin-bottom:10px;padding-top:20px;text-decoration:underline">VISION & HEARING CARE</th></tr>
    <tr><td style="width:85%"># of eye exams in the next year?</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['eye_exams']}</td></tr>
    <tr><td style="width:85%"># of eye glasses purchased in the next year?</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['eye_glasses']}</td></tr>
    <tr><td style="width:85%"># of contact lenses purchased in the next year?</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['contact_lenses']}</td></tr>
    <tr><td style="width:85%"># of eye surgeries in the next year?</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['eye_surgeries']}</td></tr>
    <tr><td style="width:85%"># of hearing exams in the next year?</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['hearing_exams']}</td></tr>  
    <tr><td style="width:85%"># of hearing aids or batteries in the next year?</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['hearing_aids']}</td></tr>
    <tr><td colspan="3">List any other vision or hearing expenses next year: </td></tr>
    <tr><td colspan="3">Answer : {$_POST['notes_vision_hearing_care']}</td></tr>


    </table>
xyz;

$chronic_list="";
$_POST['chronic_conditions']=@array_map('ucwords',$_POST['chronic_conditions']);
$chronic_list=@implode("<br>",$_POST['chronic_conditions']);
$chronic_list=($chronic_list)?($chronic_list):"-Not Applicable-";

$page2=<<<xyz
    <table style="width:100%" cellpadding="2" >
    <tr><th colspan="3" style="color:orange;margin-bottom:10px;padding-top:20px;text-decoration:underline">DENTAL CARE </th></tr>
    <tr><td style="width:85%"># of the dental exams in the next year?</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['dental_exams']}</td></tr>
    <tr><td style="width:85%"># of teeth cleanings in the next year?</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['teeth_cleanings']}</td></tr>
    <tr><td style="width:85%"># of cavity fillings in the next year?</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['cavity_fillings']}</td></tr>
    <tr><td style="width:85%"># of root canals in the next year?</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['root_canals']}</td></tr>
    <tr><td style="width:85%"># of crown, bridges or dentures in the next year?</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['crown_bridges_dentures']}</td></tr>  
    <tr><td style="width:85%"># of oral surgeries in the next year?</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['oral_surgeries']}</td></tr>
    <tr><td style="width:85%"># of braces or orthodontia in the next year?</td><td style="width:10%;text-align:center"> -- </td>
    <td style="width:5%;text-align:center;">{$_POST['braces_orthodontia']}</td></tr>
    <tr><td colspan="3">List any other dental expenses next year: </td></tr>
    <tr><td colspan="3">Answer : {$_POST['notes_dental_care']}</td></tr>

    <tr><th colspan="3" style="color:orange;margin-bottom:10px;padding-top:20px;text-decoration:underline">CHRONIC CONDITIONS </th></tr>
    <tr><td colspan="3">Does anyone who will be covered on your health insurance plan have: </td></tr>
    <tr><td colspan="3">$chronic_list</td></tr>
    <tr><td colspan="3">OTHERS: </td></tr>
    <tr><td colspan="3">Answer : {$_POST['notes_chronic_conditions']}</td></tr>
    </table>
xyz;


$pdfName="HealthCareWorkSheet.pdf";
// Have to use the curl to get our work done
    $curl = curl_init();
// Set some options - we are passing in a useragent too here
    curl_setopt_array($curl, array(
        CURLOPT_RETURNTRANSFER => 1,
        CURLOPT_URL =>$base_url."/sites/all/modules/healthcareworksheet/tcpdf/examples/pdf-report-generator.php",
        CURLOPT_USERAGENT => 'Codular Sample cURL Request',
        CURLOPT_POST => 1,
        CURLOPT_POSTFIELDS => array(
            'page1' => $page1,
            'page2' => $page2,
            'pdfName' => $pdfName,
            'pdf_link'=>$base_url."/sites/all/modules/healthcareworksheet/".$pdfName,
            'pdf_path'=>$base_path."/sites/all/modules/healthcareworksheet/".$pdfName
        )
    ));
// Send the request & save response to $resp
    $resp = curl_exec($curl);

// Close request to clear up some resources
    if(!$_POST['send_email'])
    echo drupal_set_message($resp);
    if($_POST['send_email']):
			$to = $_POST['send_email']; // to e-mail address
			$from = "web@appddictionstudio.biz"; // from e-mail address
			$subject = "SA-Access - Health Care Worksheet"; // subject of e-mail
			$message = "Please find the attached document !"; //it might be any variable from the form eg. $form_state['values']['your_field']
            $attachment=$base_path."/sites/all/modules/healthcareworksheet/".$pdfName;
			$sent=send_mail_with_attachment($to,$from,$message,$subject,$attachment);
			if($sent)
			drupal_set_message("PDF Report Sent to your mail successfully !");
		    else
		    drupal_set_message("Server encountered some problem, please try again later !",'error');   	
    endif;

    curl_close($curl);

    endif;		
}


function send_mail_with_attachment($to,$from,$message,$subject,$attachment){

// array with filenames to be sent as attachment
$files = array($attachment);
// email fields: to, from, subject, and so on
$headers = "From: SA-Access <$from>";
// boundary 
$semi_rand = md5(time()); 
$mime_boundary = "==Multipart_Boundary_x{$semi_rand}x"; 
// headers for attachment 
$headers .= "\nMIME-Version: 1.0\n" . "Content-Type: multipart/mixed;\n" . " boundary=\"{$mime_boundary}\""; 
// multipart boundary 
$message = "This is a multi-part message in MIME format.\n\n" . "--{$mime_boundary}\n" . "Content-Type: text/plain; charset=\"iso-8859-1\"\n" . "Content-Transfer-Encoding: 7bit\n\n" . $message . "\n\n"; 
$message .= "--{$mime_boundary}\n";
// preparing attachments
for($x=0;$x<count($files);$x++){
	$file = fopen($files[$x],"rb");
	$data = fread($file,filesize($files[$x]));
	fclose($file);
	$data = chunk_split(base64_encode($data));
	$message .= "Content-Type: {\"application/octet-stream\"};\n" . " name=\"$files[$x]\"\n" . 
	"Content-Disposition: attachment;\n" . " filename=\"HealthCareWorkSheet.pdf\"\n" . 
	"Content-Transfer-Encoding: base64\n\n" . $data . "\n\n";
	$message .= "--{$mime_boundary}\n";
}
// send
return @mail($to, $subject, $message, $headers); 

}

?>