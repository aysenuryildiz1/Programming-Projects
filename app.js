/* 
Ders: Programlama Dilleri Prensipleri
Öğrenci: Aysenur Yıldız
Numara: 2240656807
Ödev No: 153
Tarih: 21.05.2026
*/

/*
Bu projede JavaScript kullanılarak custom DOM event sistemi geliştirilmiştir.

Projede:
- Observer / Event Pattern
- CustomEvent yapısı
- addEventListener kullanımı
- Event Delegation tekniği

uygulanmıştır.

Kullanıcı görev eklediğinde, sildiğinde, tamamladığında
ve filtreleme yaptığında özel eventler tetiklenmektedir.
*/


// Görev ekleme butonunu seçiyoruz
const addTaskBtn = document.getElementById("addTaskBtn");

// Kullanıcının görev yazdığı input alanını seçiyoruz
const taskInput = document.getElementById("taskInput");

// Görevlerin ekleneceği liste alanını seçiyoruz
const taskList = document.getElementById("taskList");

// Filtreleme butonlarının tamamını seçiyoruz
const filterButtons = document.querySelectorAll(".filter-btn");




// GÖREV EKLEME İŞLEMİ


/*
Kullanıcı "Görev Ekle" butonuna bastığında:
1) Input içindeki görev alınır
2) Yeni görev oluşturulur
3) Sayfaya eklenir
4) taskAdded isimli custom event yayınlanır
*/

addTaskBtn.addEventListener("click", function () {

    // Kullanıcının yazdığı görevi alıyoruz
    const taskText = taskInput.value.trim();


    /*
    Eğer kullanıcı boş görev eklemeye çalışırsa
    işlem durdurulur ve uyarı verilir.
    */
    if (taskText === "") {

        alert("Lütfen görev giriniz!");

        return;
    }


    // Yeni bir liste elemanı oluşturuyoruz
    const li = document.createElement("li");


    // Oluşturulan elemana CSS class ekleniyor
    li.classList.add("task-item");


    /*
    Görevin HTML yapısı hazırlanıyor.

    Her görev için:
    - görev yazısı
    - tamamla butonu
    - sil butonu

    oluşturulmaktadır.
    */
    li.innerHTML = `
    
        <span>${taskText}</span>

        <div>

            <button class="complete-btn">
                Tamamla
            </button>

            <button class="delete-btn">
                Sil
            </button>

        </div>
    `;


    // Oluşturulan görev listeye ekleniyor
    taskList.appendChild(li);


    // İşlem bittikten sonra input temizleniyor
    taskInput.value = "";



  
    // CUSTOM EVENT -> taskAdded
  

    /*
    Burada CustomEvent kullanılarak
    taskAdded isimli özel event oluşturuluyor.

    detail alanı ile event içerisine veri gönderiyoruz.
    */

    const taskAddedEvent = new CustomEvent(
        "taskAdded",
        {
            detail: {
                taskName: taskText
            }
        }
    );


    /*
    dispatchEvent kullanılarak event yayınlanıyor.

    Bu yapı Observer Pattern mantığı ile çalışır.
    */
    document.dispatchEvent(taskAddedEvent);

});





// OBSERVER / EVENT PATTERN


/*
Bu bölümde Observer Pattern uygulanmaktadır.

Publisher:
document.dispatchEvent()

Subscriber:
document.addEventListener()

Event yayınlanır ve dinleyiciler tarafından yakalanır.
*/


// taskAdded event'ini dinleyen observer
document.addEventListener(
    "taskAdded",
    function (event) {

        console.log(
            "Yeni görev eklendi:",
            event.detail.taskName
        );
    }
);





// EVENT DELEGATION


/*
Event Delegation tekniği kullanılmaktadır.

Her butona ayrı ayrı event vermek yerine,
parent element olan taskList üzerine
tek event listener eklenmiştir.

Bu yöntem performans açısından daha verimlidir.
*/

taskList.addEventListener("click", function (event) {


    
    // GÖREV SİLME İŞLEMİ
    

    /*
    Kullanıcı sil butonuna basarsa
    ilgili görev listeden kaldırılır.
    */

    if (event.target.classList.contains("delete-btn")) {

        // Silinecek görev bulunuyor
        const taskItem = event.target.closest(".task-item");


        // Görev ekrandan kaldırılıyor
        taskItem.remove();



        
        // CUSTOM EVENT -> taskDeleted
        

        /*
        Görev silindiğinde taskDeleted
        isimli özel event oluşturuluyor.
        */

        const deleteEvent = new CustomEvent(
            "taskDeleted"
        );


        // Event yayınlanıyor
        document.dispatchEvent(deleteEvent);
    }



   
    // GÖREV TAMAMLAMA İŞLEMİ
   

    /*
    Kullanıcı tamamla butonuna bastığında
    görevin tamamlanma durumu değiştirilir.
    */

    if (event.target.classList.contains("complete-btn")) {

        // Tamamlanacak görev bulunuyor
        const taskItem = event.target.closest(".task-item");


        /*
        completed class'ı eklenir veya kaldırılır.

        Böylece görevin üstü çizilir.
        */
        taskItem.classList.toggle("completed");



        
        // CUSTOM EVENT -> taskCompleted
       

        /*
        Görev tamamlandığında
        taskCompleted event'i oluşturulur.
        */

        const completedEvent = new CustomEvent(
            "taskCompleted"
        );


        // Event yayınlanıyor
        document.dispatchEvent(completedEvent);
    }

});





// GÖREV FİLTRELEME İŞLEMİ


/*
Bu bölümde görevler filtrelenmektedir.

all -> tüm görevler
completed -> tamamlanan görevler
active -> aktif görevler
*/

filterButtons.forEach(function (button) {

    button.addEventListener("click", function () {

        // Basılan butonun filtre türü alınır
        const filterType =
            button.dataset.filter;


        // Tüm görevler seçilir
        const tasks =
            document.querySelectorAll(".task-item");



        // Her görev üzerinde işlem yapılır
        tasks.forEach(function (task) {

            // Tüm görevleri göster
            if (filterType === "all") {

                task.style.display = "flex";
            }

            // Sadece tamamlanan görevleri göster
            else if (filterType === "completed") {

                if (task.classList.contains("completed")) {

                    task.style.display = "flex";
                }

                else {

                    task.style.display = "none";
                }
            }

            // Sadece aktif görevleri göster
            else if (filterType === "active") {

                if (!task.classList.contains("completed")) {

                    task.style.display = "flex";
                }

                else {

                    task.style.display = "none";
                }
            }

        });



        
        // CUSTOM EVENT -> taskFiltered
        

        /*
        Filtreleme işlemi yapıldığında
        taskFiltered event'i oluşturulur.
        */

        const filterEvent = new CustomEvent(
            "taskFiltered",
            {
                detail: {
                    filter: filterType
                }
            }
        );


        // Event yayınlanıyor
        document.dispatchEvent(filterEvent);

    });

});





// EVENT DİNLEYİCİLERİ


/*
Aşağıdaki listener'lar oluşturulan
custom eventleri dinlemektedir.
*/


// taskDeleted event'ini dinler
document.addEventListener(
    "taskDeleted",
    function () {

        console.log("Görev silindi");
    }
);


// taskCompleted event'ini dinler
document.addEventListener(
    "taskCompleted",
    function () {

        console.log("Görev tamamlandı");
    }
);


// taskFiltered event'ini dinler
document.addEventListener(
    "taskFiltered",
    function (event) {

        console.log(
            "Filtre uygulandı:",
            event.detail.filter
        );
    }
);




/*
Bu projede kullanılan custom eventler:

1) taskAdded
2) taskDeleted
3) taskCompleted
4) taskFiltered

Bu eventler sayesinde custom DOM event sistemi
başarılı şekilde uygulanmıştır.
*/