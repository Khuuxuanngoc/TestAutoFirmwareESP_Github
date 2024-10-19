// Đang dung devshop2019g
// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
  apiKey: "AIzaSyBe0nYHl2JxNRqOgXAFxrtRDrl6Vz7uXrk",
  authDomain: "esp8266firmware-812f5.firebaseapp.com",
  projectId: "esp8266firmware-812f5",
  storageBucket: "esp8266firmware-812f5.appspot.com",
  messagingSenderId: "1016993896504",
  appId: "1:1016993896504:web:fcdc15db6ee17fddee2ecd",
  measurementId: "G-66SN68Q0Q7"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const analytics = getAnalytics(app);